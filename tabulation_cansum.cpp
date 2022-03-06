#include <iostream>
#include <vector>

bool canSum(uint32_t target,const std::vector<uint32_t>& numbers)
{
    std::vector<bool> table(target+1, false);
    
    table[0] = true;
    
    for(uint32_t i = 0; i < table.size(); i++)
    {
        if(table.at(i))
        {
            for(auto it : numbers)
            {
                if(i + it < table.size()) 
                {
                    table.at(i + it) = true;
                }
            }
        }
    }
    
    
    return table[target];
}

int main()
{
    uint32_t target = 444;
    std::vector<uint32_t> numbers = {5,3,4};
    
    bool result = canSum(target,numbers);
    
    if(result)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl; 
    }

    return 0;
}
