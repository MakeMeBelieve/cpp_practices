#include <iostream>
#include <vector>
#include <string>

bool bestSum(uint32_t target,const std::vector<uint32_t>& numbers, std::vector<uint32_t>& result)
{
    std::vector<std::vector<uint32_t>> table(target+1, std::vector<uint32_t>(0));
    
    table[0].push_back(0);
    
    std::vector<uint32_t> combination;
    
    for(uint32_t i = 0; i <= target; i++)
    {
        if(table[i].size() != 0)
        {
            for(auto it : numbers)
            {
                if(i + it <= target)
                {
                    combination = table[i];
                    combination.push_back(it);
                    
                    if(table[i + it].size() == 0 || combination.size() < table[i+ it].size())
                    {
                        table[i + it] = combination;
                    }
                }
            }
        }
    }
    
    
    if(table[target].size() > 0)
    {
        table[target].erase(table[target].begin()); //delete 0
        result = table[target];
        return true;
    }
    
    return false;
    
}

int main()
{
    uint32_t target = 32;
    std::vector<uint32_t> numbers = {2, 4, 16};
    std::vector<uint32_t> result;
    bool resultValidate = false;
    
    resultValidate = bestSum(target, numbers, result);
    
    if(resultValidate)
    {
        std::string msg("Result: ");
        
        for(auto it : result)
        {
            msg += std::to_string(it) + ", ";
        }
        
        std::cout << msg << std::endl;
    }
    else
    {
        std::cout << "Result: nullptr" << std::endl;
    }
    

    return 0;
}

