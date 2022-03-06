#include <stdio.h>
#include <iostream>
#include <array>
#include <string>
#include <ctime>
#include <map>

template<std::size_t SIZE>
bool canSum(int32_t TotalSum, std::array<uint32_t, SIZE>& numbers)
{
    if(TotalSum == 0) return true;
    if(TotalSum < 0) return false;
 
    for(const auto& it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        //debug
        std::cout << ">" <<std::to_string(TotalSum) + " - " + 
        std::to_string(it) + " = " + std::to_string(diff) << std::endl;
        //debug
        
        if(canSum(diff, numbers))
        {
            return true;
        }
    }
    
    return false;
}

template<std::size_t SIZE>
bool canSum_memo(int32_t TotalSum, std::array<uint32_t, SIZE>& numbers, std::map<int32_t, bool>& memo)
{
    if(TotalSum == 0) return true;
    if(TotalSum < 0)  return false;
    if(TotalSum == 1) return false;
 
    auto m = memo.find(TotalSum);
    if(m != memo.end())
    {
        //debug
        std::cout << "finded TotalSum: " << std::to_string(TotalSum) << "-->"
        << ((m->second) ? "TRUE" : "FALSE") << std::endl;
        //debug
        
        return m->second;
    }
    
    for(const auto& it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        //debug
        std::cout << ">" <<std::to_string(TotalSum) + " - " + 
        std::to_string(it) + " = " + std::to_string(diff) << std::endl;
        //debug
        
        memo[TotalSum] = canSum_memo(diff, numbers, memo);
        
        if(memo[TotalSum])
        {
            return true;
        }
    }
    
    memo[TotalSum] = false;
    return false;
}


int main()
{
    std::array<uint32_t, 3> list = {2,4,8};
    int total = 15;
    bool result = false;
    
    std::clock_t start;
    start = std::clock();
    
    result = canSum(total, list);
    
    double diff = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    
    std::cout <<  "Duration: " << std::to_string(diff) << std::endl;
    
    if(result)
        std::cout << "Result: True" << std::endl;
    else
        std::cout << "Result: False" << std::endl;
    
    start = std::clock();
    
    std::map<int32_t, bool> memo;
    result = canSum_memo(total, list, memo);
    
    diff = (std::clock() - start) / (double) CLOCKS_PER_SEC;
    
    std::cout <<  "Duration: " << std::to_string(diff) << std::endl;
    
    if(result)
        std::cout << "Result: True" << std::endl;
    else
        std::cout << "Result: False" << std::endl;
    
    return 0;
}

