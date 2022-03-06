#include <iostream>
#include <string>
#include <vector>

uint32_t countConstruct(const std::string target, const std::vector<std::string>& words)
{
    std::vector<uint32_t> table(target.length() + 1, 0);
    table[0] = 1; // there is always 1 way of creating nullstring.
    
    for(uint32_t i = 0; i <= target.length(); i++)
    {
        if(table[i] > 0)
        {
            for( auto it : words)
            {
                std::string subWord = target.substr(i, it.length());
                
                if(subWord.compare(it) == 0)
                {
                    table[i + it.length()] += table[i];
                }
            }
        }
    }
    
    return table[target.length()];
}

int main()
{
    std::string target = "purple";
    std::vector<std::string> words = {"purp", "p", "ur", "le", "purpl" };
    uint32_t count = 0;
    
    count = countConstruct(target, words);
    
    std::cout << count << std::endl;
    

    return 0;
}