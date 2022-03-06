#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <map>

bool howSum(int32_t TotalSum, const std::vector<uint32_t>& numbers, std::vector<uint32_t>& result)
{
    if(TotalSum == 0)
    {
        //debug
        //std::cout << "True TotalSum -> 0" << std::endl; 
        //debug
        result.clear();
        return true;
    } 
    if(TotalSum < 0) return false;
    
    for(auto it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        //debug
        //std::cout << ">" << std::to_string(TotalSum) << " - " << std::to_string(it) <<
        //" -> " << std::to_string(diff) << std::endl;
        //debug
        
        if(howSum(diff, numbers,result))
        {
            result.push_back(it);
            return true;
        }
    }
    
    return false;
}

bool howSum_memo(int32_t TotalSum,const std::vector<uint32_t>& numbers, 
std::map<int32_t,bool>& memo, std::vector<uint32_t>& result)
{
    if(TotalSum == 0)
    {
        result.clear();
        return true;
    }
    if(TotalSum < 0) return false;
    if(TotalSum == 1) return false;
    
    auto mapped = memo.find(TotalSum);
    
    if(mapped != memo.end())
    {
        //debug
        //std::cout << "Memo[" << std::to_string(TotalSum) << "]-> " << 
        //std::to_string(mapped->second) << std::endl;
        //debug
        
        return mapped->second;
    }
    
    for(auto it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        //debug
        //std::cout << ">" << std::to_string(TotalSum) << " - " << std::to_string(it) <<
        //" -> " << std::to_string(diff) << std::endl;
        //debug
        
        memo[TotalSum] = howSum_memo(diff,numbers,memo,result);
        
        if(memo[TotalSum])
        {
            result.push_back(it);
            return true;
        }
    }
    
    return false;
}

int main()
{
    std::vector<uint32_t> numbers = {2,4};
    uint32_t TotalSum = 61;
    
    std::vector<uint32_t> result;
    auto resultValid = false;
    std::clock_t startClock;
    double duration = 0.0f;
    
    startClock =  clock();
    
    resultValid = howSum(TotalSum, numbers, result);
    
    duration = (startClock - clock()) / (double) CLOCKS_PER_SEC;
    std::cout << "duration: " << std::to_string(duration) << std::endl;
    
    if(resultValid)
    {
        std::cout << "result: True Vector: [";
        
        for(auto it : result)
        {
            std::cout << std::to_string(it) << " ";
        }
        
        std::cout << "]" <<std::endl;
    }
    else
    {
        std::cout << "result: False Vector: nullptr" << std::endl;
    }
    
    //memoization
    
    startClock =  clock();
    
    std::map<int32_t, bool> memo;
    resultValid = howSum_memo(TotalSum, numbers, memo, result);
    
    duration = (startClock - clock()) / (double) CLOCKS_PER_SEC;
    std::cout << "duration: " << std::to_string(duration) << std::endl;
    
    if(resultValid)
    {
        std::cout << "result: True Vector: [";
        
        for(auto it : result)
        {
            std::cout << std::to_string(it) << " ";
        }
        
        std::cout << "]" <<std::endl;
    }
    else
    {
        std::cout << "result: False Vector: nullptr" << std::endl;
    }

    return 0;
}


