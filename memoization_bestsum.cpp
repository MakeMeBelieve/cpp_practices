#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <map>

static std::vector<uint32_t> treeIndex;
    
//find shortest sum of TotalSum value using numbers vector
bool bestSum(int32_t TotalSum, const std::vector<uint32_t>& numbers, 
 std::vector<uint32_t>& result)
{
    if(TotalSum == 0) return true;
    if(TotalSum < 0)  return false;
    if(TotalSum == 1) return false;
    
    std::vector<uint32_t> prevTemp;

    for(auto it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        //debug
        //std::cout << ">" << std::to_string(TotalSum) << " - " << std::to_string(it) 
        //<< " -> " << std::to_string(diff) << std::endl;
        //debug
        
        treeIndex.push_back(it);
        
        if(bestSum(diff, numbers, result))
        {
            if(prevTemp.size() == 0 || treeIndex.size() < prevTemp.size())
            {
                prevTemp.clear();
                
                for(uint32_t i = 0; i < treeIndex.size(); i++)
                    prevTemp.push_back(treeIndex[i]);
            }
        }
        
        treeIndex.pop_back();
    }
    
    if(prevTemp.size() > 0)
    {
        result.clear();
        
        for(uint32_t i = 0; i < prevTemp.size(); i++)
        {
            result.push_back(prevTemp[i]);
        }
        
    }
    
    return false;
}

bool bestSum_memo(int32_t TotalSum, const std::vector<uint32_t>& numbers, std::vector<uint32_t>& result,
std::map<int32_t,std::vector<uint32_t>>& memo)
{
    if(TotalSum == 0) return true;
    if(TotalSum < 0 ) return false;
    if(TotalSum == 1) return false;
    
    auto mapped = memo.find(TotalSum);
    
    if(mapped != memo.end())
    {
        //debug
        std::cout << "Mapped[" << std::to_string(TotalSum) << "] -> [";
        for(uint32_t i = 0; i < mapped->second.size(); i++)
        {
            std::cout << std::to_string(mapped->second[i]) << " "; 
        }
        std::cout << "]" << std::endl;
        //debug
        
        result = mapped->second;
        return false;
    }

    std::vector<uint32_t> temp;
    
    for(auto it : numbers)
    {
        int32_t diff = TotalSum - it;
        
        treeIndex.push_back(it);
        
        //debug
        std::cout << ">" << std::to_string(TotalSum) << " - " << std::to_string(it) 
        << " -> " << std::to_string(diff) << std::endl;
        //debug
        
        if(bestSum_memo(diff, numbers, result,memo))
        {
            if(temp.size() == 0 || treeIndex.size() < temp.size())
            {
                temp.clear();
                
                for(uint32_t i = 0; i < treeIndex.size(); i++)
                {
                    temp.push_back(treeIndex[i]);
                }
            }
        }
        
        treeIndex.pop_back();
    }
    
    if(temp.size() > 0)
    {
        result.clear();
        
        for(uint32_t i = 0; i < temp.size(); i++)
        {
            result.push_back(temp[i]);
        }
        
        memo[TotalSum] = result;
    }
    
    return false;
}

int main()
{
    std::vector<uint32_t> numbers = {25,50};
    int32_t TotalSum = 100;
    
    std::vector<uint32_t> result;
    bool resultValidate = false;
    std::clock_t startClock;
    double duration = 0.0f;
    
    startClock = clock();
    
    treeIndex.clear();
    bestSum(TotalSum, numbers, result);
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    std::cout << "Duration: " << std::to_string(duration) << std::endl;
    
    if(result.size() > 0)
    {
        std::cout << "Best Sum: [";
        
        for(auto it : result)
        {
            std::cout << std::to_string(it) << " ";
        }
        
        std::cout << "]" << std::endl;
    }
    else
    {
        std::cout << "Best Sum: nullptr" << std::endl;
    }
    
    //memoization
    std::map<int32_t, std::vector<uint32_t>> memo;
    
    startClock = clock();
    
    treeIndex.clear();
    bestSum_memo(TotalSum, numbers, result, memo);
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    std::cout << "Duration: " << std::to_string(duration) << std::endl;
    
    if(result.size() > 0)
    {
        std::cout << "Best Sum: [";
        
        for(auto it : result)
        {
            std::cout << std::to_string(it) << " ";
        }
        
        std::cout << "]" << std::endl;
    }
    else
    {
        std::cout << "Best Sum: nullptr" << std::endl;
    }

    

    return 0;
}
