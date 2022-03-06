#include <iostream>
#include <string>
#include <vector>

bool canConstruct(const std::string target,const std::vector<std::string>& words)
{
    std::vector<bool> table(target.length() + 1, false);
    
    table[0] = true;
    
    for(uint32_t i = 0; i <= target.length(); i++)
    {
        if(table[i])
        {
            for(auto it : words)
            {
                std::string word = target.substr(i, it.length());
                
                if(word.compare(it) == 0)
                {
                    table[i + word.length()] = true;
                }
            }
        }
    }
    
    return table[target.length()];
}

int main()
{
    std::string target = "abcdef";
    std::vector<std::string> words = {"ab", "abc", "cd", "def", "abcd"};
    bool resultValidate = false;
    
    resultValidate = canConstruct(target, words);
    
    if(resultValidate)
        std::cout << "Result: True" << std::endl;
    else
        std::cout << "Result: False"  << std::endl;
    

    return 0;
}