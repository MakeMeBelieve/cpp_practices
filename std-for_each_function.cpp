#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<std::string> vec(5, "q2w2");
    
    std::for_each(vec.cbegin(),vec.cend(), [](const auto& i){std::cout << i << std::endl;});


    std::vector<uint32_t> vec2 {1,3,5,7,9};
    
    std::for_each(vec2.begin(), vec2.end(), [](auto& i){std::cout << i++ << std::endl; });
    
   
    std::vector<uint32_t> vec4(vec2.begin(),vec2.end());
    
    std::for_each(vec4.begin(), vec4.end(), [](auto& i){std::cout << i << std::endl; });
    
    return 0;
}
