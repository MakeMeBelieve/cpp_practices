#include <iostream>
#include <string>
#include <vector>

void allConstruct(const std::string target,const std::vector<std::string>& words,
 std::vector<std::vector<std::string>>& allCombinations)
{
    std::vector<std::vector<std::vector<std::string>>> table(target.length() + 1);
    
    table[0] = {{ "*" }};
    
    for(uint32_t i = 0; i <= target.length(); i++)
    {
        if(table[i].size() != 0)
        {
            for(auto it : words)
            {
                std::string subWord = target.substr(i, it.length());
                
                if(subWord.compare(it) == 0)
                {
                    for(uint32_t j = 0; j < table[i].size(); j++)
                        table[i + it.length()].push_back(table[i][j]);
                    
                    for(uint32_t j = 0; j < table[i + it.length()].size(); j++)
                        table[i + it.length()][j].push_back(it);
                }
            }
        }
    }
    
    for(auto it : table[target.length()])
    { 
       it.erase(it.begin()); //delete [*]
    }
    
    allCombinations = table[target.length()];
}


int main()
{
    std::string target = "abcdef";
    std::vector<std::string> words = {"ab", "abc", "cd", "def", "abcd", "ef", "c"};
    
    std::vector<std::vector<std::string>> allCombinations;

    allConstruct(target, words, allCombinations);
    
    std::string msg("Result: \n");
    
    for(auto it : allCombinations)
    {
        msg += "[";
        
        for(auto word : it)
        {
            msg += word + ",";
        }
        
        msg += "] \n";
    }
    
    std::cout << msg << std::endl;

    return 0;
}