#include <iostream>
#include <vector>

uint32_t gridTraveller(uint32_t m, uint32_t n)
{
    std::vector<std::vector<uint32_t>> table(n+1, std::vector<uint32_t>(m+1));
    
    table[1][1] = 1;
    
    for(uint32_t i = 0; i <= n; i++)
    {
        for(uint32_t j = 0; j <= m; j++)
        {
            if(i+1 <= n) table[i+1][j] += table[i][j];
            if(j+1 <= m) table[i][j+1] += table[i][j];
        }
    }
    
    return table[n][m];
}

int main()
{

    uint32_t paths = gridTraveller(18,18);
    
    std::cout << std::to_string(paths) << std::endl;

    return 0;
}