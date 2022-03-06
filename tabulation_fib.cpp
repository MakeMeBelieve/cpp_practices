#include <iostream>
#include <vector>


uint32_t fib(uint32_t n)
{
    std::vector<uint32_t> table(n+1);
    
    table[1] = 1;
    
    for(uint32_t i = 0; i <= n; i++)
    {
        table[i + 1] += table[i];
        table[i + 2] += table[i];
        
        //debug
        //std::cout << std::to_string(table[i + 1]) << std::endl;
    }
    
    return table[n+1];
}

int main()
{
    uint32_t n = 10;
    
    uint32_t result = fib(n);
    
    std::cout << "result: " << std::to_string(result) << std::endl;

    return 0;
}