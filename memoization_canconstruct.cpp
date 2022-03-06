#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <map>

bool canConstruct(std::string target, std::vector<std::string>& wordBank)
{
    if(target == "") return true;
    
    //debug
    std::cout << target << std::endl;
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            std::string word = target.substr(it.length());
            
            if(canConstruct(word, wordBank))
            {
                //debug
                std::cout << word << std::endl;
                return true;
            }
        }
    }
    
    return false;
}

bool canConstruct_memo(std::string target, std::vector<std::string>& wordBank, 
std::map<std::string,bool>& memo)
{
    if(target == "") return true;
    
    auto mapped = memo.find(target);
    
    if(mapped != memo.end())
    {
        //debug
        std::cout << "Mapped[" << target << "] -> " <<
        mapped->second << std::endl;
        
        return mapped->second;
    }
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            auto word = target.substr(it.length());
            
            if(canConstruct_memo(word,wordBank,memo))
            {
                //debug
                std::cout << word << std::endl;
                
                memo[target] = true;
                return true;
            }
        }
        
    }
    
    memo[target] = false;
    return false;
}

int main()
{
    std::string target("eeeeeeeeeeeeef");
    std::vector<std::string> wordBank = {"eee","ed","cd","eeee","e","sk","a","ee"};
    
    std::clock_t startClock;
    double duration = 0.0f;
    bool result = false;
    
    startClock = clock();
    
    result = canConstruct(target, wordBank);
    
    if(result)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    std::cout << "duration: " << std::to_string(duration) << std::endl;
    
    startClock = clock();
    
    std::map<std::string,bool> memo;
    result = canConstruct_memo(target, wordBank, memo);
    
    if(result)
    {
        std::cout << "true" << std::endl;
    }
    else
    {
        std::cout << "false" << std::endl;
    }
    
    duration = (clock() - startClock) / (double) CLOCKS_PER_SEC;
    std::cout << "duration: " << std::to_string(duration) << std::endl;
    

    return 0;
}