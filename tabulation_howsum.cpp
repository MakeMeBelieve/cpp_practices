#include <iostream>
#include <vector>
#include <ctime>

bool howSum(uint32_t target,const std::vector<uint32_t>& numbers, std::vector<uint32_t>& result)
{
    std::vector<std::vector<uint32_t>> table(target+1, std::vector<uint32_t>(0));
    
    table[0].push_back(0);
    
    for(uint32_t i = 0; i <= target; i++)
    {
        if(table[i].size() != 0)
        {
            for(auto it : numbers)
            {
                if(i + it <= target) 
                {
                    table[i + it] = table[i];
                    table[i + it].push_back(it);
                }
            }
        }
    }
    
    
    if(table[target].size() != 0)
    {
        table[target].erase(table[target].begin()); // delete 0
        result = table[target];
        return true;
    }
    
    return false;
}


int main()
{
    std::clock_t startClock;
    double duration = 0.0f;
    
    uint32_t target = 19;
    std::vector<uint32_t> numbers = {3,5,7};
    std::vector<uint32_t> result;
    bool resultValidate = false;
    
    startClock = clock();
    
    resultValidate = howSum(target, numbers, result);
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    
    if(resultValidate)
    {
        std::string msg("Result : ");
        
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
    
   
    std::cout << "Time: " <<std::to_string(duration) << std::endl;
    
    return 0;
}