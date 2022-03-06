#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>

void allConstruct(std::string target,const std::vector<std::string>& wordBank, 
 std::vector<std::vector<std::string>>& allResults, bool& addResult)
{
    if(target == "") 
    {
        allResults.clear();
        addResult = true;
        return;
    }
    
    std::vector<std::vector<std::string>> result;
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            //debug
            std::cout << target << "**" << std::endl;
            
            auto word = target.substr(it.length());
            
            //debug
            std::cout << word << "-*-" << it << std::endl;
            
            if(result.size() == 0)
            {
                std::vector<std::string> init = {it};
                result.push_back(init);   
            }
            else
            {
               for(uint32_t i = 0; i < result.size(); i++)
                {
                    result[i].insert(result[i].begin() ,it);
                } 
            }
            
            bool valid = false;
            allConstruct(word, wordBank, allResults, valid);
            
            if(valid)
            {
                for(uint32_t i = 0; i < allResults.size(); i++)
                {
                    result.push_back(allResults[i]);
                }
                
                for(uint32_t i = 0; i < result.size(); i++)
                {
                    result[i].insert(result[i].begin() ,it);
                } 
                    
                allResults.clear();
            }
           
            for(uint32_t i = 0; i < result.size(); i++)
            {
                result[i].erase(result[i].begin());
            }
        }
    }
    
    if(result.size() > 0)
    {
        allResults.clear();
        allResults = result;
        addResult = true;
    }
    else
    {
        allResults.clear();
        addResult = false; 
    }

}

void allConstruct_memo(std::string target,const std::vector<std::string>& wordBank,
std::vector<std::vector<std::string>>& allResults, bool& addResult, 
std::map<std::string,std::vector<std::vector<std::string>>>& memo, std::map<std::string,bool>& memoBool)
{
    if(target == "") 
    {
        allResults.clear();
        addResult = true;
        return;
    }
    
    auto mapped = memo.find(target);
    
    if(mapped != memo.end())
    {
        allResults.clear();
        allResults = mapped->second;
        auto mappedBoolean = memoBool.find(target);
        addResult = mappedBoolean->second;
        
        //debug
        std::cout << "mapped[" << target << "] -> used" << std::endl;
        
        return;
    }
    
    std::vector<std::vector<std::string>> temp;
    
    for(auto it : wordBank)
    {
        if(target.find(it) == 0)
        {
            auto word = target.substr(it.length());
            
            //debug
            //std::cout << word << std::endl;
            
            bool valid = false;
            allConstruct_memo(word,wordBank, allResults, valid, memo, memoBool);
            
            if(valid)
            {
                if(allResults.size() == 0)
                {
                    std::vector<std::string> init = {it};
                    temp.push_back(init); 
                }
                else
                {
                    for(uint32_t i = 0; i < allResults.size(); i++)
                    {
                        temp.push_back(allResults.at(i));
                    }
                    
                    for(uint32_t i = 0; i < temp.size(); i++)
                    {
                        temp.at(i).insert(temp.at(i).begin(), it);
                    }
                }
                
                allResults.clear();
            }
        }
    }
    
    if(temp.size() > 0)
    {
        allResults.clear();
        allResults = temp;
        addResult = true;
        memo[target] = allResults;
        memoBool[target] = true;
    }
    else
    {
        allResults.clear();
        addResult = false;
        memo[target] = allResults;
        memoBool[target] = false;
    }
    
}

int main()
{
    std::string target = "eeeef";
    std::vector<std::string> wordBank = {"ee", "eeef", "dd", "da", "fee", "f", "e" };
    
    std::vector<std::vector<std::string>> results;
    bool resultValid = false;
    std::clock_t startClock;
    double duration = 0.0f;
    
    startClock = clock();
    
    allConstruct(target, wordBank, results, resultValid);
    
    duration = (clock()- startClock) / (double) CLOCKS_PER_SEC;
    std::cout<< "duration: " << std::to_string(duration) << std::endl;
    
    if(resultValid)
    {
        std::cout << "{" << std::endl;
        for(uint32_t i = 0; i < results.size(); i++)
        {
            std::cout << " [";
            uint32_t k;
            for(k = 0; k < results.at(i).size() - 1 ; k++)
            {
                std::cout << results.at(i).at(k) << ","; 
            }
            std::cout << results.at(i).at(k); 
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
        std::cout << " }" << std::endl;
    }
    else
    {
        std::cout << "nullptr" << std::endl;
    }
    
    //memoization
    
    std::map<std::string,std::vector<std::vector<std::string>>> memo;
    std::map<std::string,bool> memoBoolean;
    
    startClock = clock();
    resultValid = false;
    
   // allConstruct_memo(target, wordBank, results, resultValid,memo, memoBoolean);
    
    duration = (clock()- startClock) / (double) CLOCKS_PER_SEC;
    std::cout<< "duration: " << std::to_string(duration) << std::endl;
    
    if(resultValid)
    {
        std::cout << "{" << std::endl;
        for(uint32_t i = 0; i < results.size(); i++)
        {
            std::cout << " [";
            uint32_t k;
            for(k = 0; k < results.at(i).size() - 1 ; k++)
            {
                std::cout << results.at(i).at(k) << ","; 
            }
            std::cout << results.at(i).at(k); 
            std::cout << "]" << std::endl;
        }
        std::cout << std::endl;
        std::cout << " }" << std::endl;
    }
    else
    {
        std::cout << "nullptr" << std::endl;
    }
    
    

    return 0;
}

