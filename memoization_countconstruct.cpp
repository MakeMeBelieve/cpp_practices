#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

uint32_t countConstruct(std::string target,const std::vector<std::string>& wordBank)
{
    if(target == "") return 1;
    
    uint32_t result = 0;
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            auto word = target.substr(it.length());
            uint32_t subTreeCount = countConstruct(word, wordBank);
            result += subTreeCount;
            
            //debug
            //std::cout << word << std::endl;
        }
    }
    
    return result;
}

uint32_t countConstruct_memo(std::string target,const std::vector<std::string>& wordBank, 
std::map<std::string,uint32_t>& memo)
{
    if(target == "") return 1;
    
    auto mapped = memo.find(target);
    
    if(mapped != memo.end())
    {
        //debug
        //std::cout << "Mapped[" << target << "] -> " << std::to_string(mapped->second) << std::endl;
        return mapped->second;
    }
    
    uint32_t result = 0;
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            auto word = target.substr(it.length());
            
            uint32_t subTreeCount = countConstruct_memo(word, wordBank, memo);
            result += subTreeCount;
        }
    }
    
    memo[target] = result;
    return result;
}

int main()
{
    std::string target = "eeeeeeeeeeeeeeeeef";
    std::vector<std::string> wordBank = {"ee", "eeee", "eeff","sk", "ct", "aaa", "e", "eee", "eeef"};

    std::clock_t startClock;
    double duration = 0.0f;
    
    startClock = clock();

    uint32_t count = countConstruct(target, wordBank);
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    
    std::cout << "Possible way count: " << count << std::endl;
    std::cout << "Duration :" << duration << std::endl;
    
    startClock = clock();

    std::map<std::string, uint32_t> memo;
    count = countConstruct_memo(target, wordBank, memo);
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    
    std::cout << "Possible way count: " << count << std::endl;
    std::cout << "Duration :" << duration << std::endl;

    return 0;
}



