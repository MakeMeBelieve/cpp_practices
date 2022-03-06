#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
#include <map>

static uint32_t gridTraveller (uint32_t m, uint32_t n)
{
  if (m == 1 && n == 1) return 1;
  if (m == 0 || n == 0) return 0;
  return gridTraveller (m - 1, n) + gridTraveller (m, n - 1);
}

static uint32_t gridTraveller_memo (uint32_t m, uint32_t n, 
    std::map<std::string, int32_t>& memo)
{
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    
    std::string key = std::to_string(m) + "," + std::to_string(n);
    auto it = memo.find(key);
    
    if(it == memo.end())
    {
        return memo[key] = gridTraveller_memo(m-1, n, memo) +
        gridTraveller_memo(m, n-1, memo);
    }
    
    return it->second;
}

static uint32_t gridTraveller_memo_simetric(uint32_t m, uint32_t n, 
    std::map<std::string, int32_t>& memo)
{
    if (m == 1 && n == 1) return 1;
    if (m == 0 || n == 0) return 0;
    
    std::string key = std::to_string(m) + "," + std::to_string(n);
    auto it = memo.find(key);  
    
    if(it == memo.end() && m != n)
    {
        std::string key_simetric  = std::to_string(n) + "," + std::to_string(m);
        auto it_simetric = memo.find(key_simetric);
        
        if(it_simetric != memo.end())
        {
            return it_simetric->second;
        }
    }

    if(it == memo.end())
    {
        return memo[key] = gridTraveller_memo_simetric(m-1, n, memo) +
        gridTraveller_memo_simetric(m, n-1, memo);
    }
    
    return it->second;
}

int main ()
{
  auto gridDimention = 15;
  std::clock_t start;
  double duration;
  start = std::clock ();

  //counts of paths in grid way
  //only go right or down
  std::cout << "paths count:" << gridTraveller (gridDimention, gridDimention)
   << std::endl;

  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "duration:" << duration << std::endl;
  
  start = std::clock ();

  //memo
  std::map<std::string, int32_t> memo;
  std::cout << "paths count:" << gridTraveller_memo (gridDimention, 
  gridDimention, memo) << std::endl;

  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "duration:" << duration << std::endl;
  
    start = std::clock ();

  //memo_simetric key => grid(3,4) = grid(4,3)
  std::map<std::string, int32_t> memo_simetric;
  std::cout << "paths count:" << gridTraveller_memo_simetric (gridDimention, 
  gridDimention, memo_simetric) << std::endl;

  duration = (std::clock () - start) / (double) CLOCKS_PER_SEC;
  std::cout << "duration:" << duration << std::endl;
  
  return 0;
}


