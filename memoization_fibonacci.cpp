#include <iostream>
#include <cstdio>
#include <ctime>
#include <map>


static uint32_t fib(uint32_t n)
{
  if (n <= 2)
    return 1;
  return fib(n - 1) + fib(n - 2);
}

static uint32_t fib_memo(uint32_t n, std::map <uint32_t,uint32_t>&memo)
{
  if (n <= 2)
    return 1;

  auto it = memo.find(n);

  if (it == memo.end())
    {
      return memo[n] = fib_memo(n - 1, memo) + fib_memo(n - 2, memo);
    }

  return it->second;
}

int main ()
{
  std::clock_t start;
  double duration;
  start = std::clock();

  std::cout << fib(45) << std::endl;

  duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
  std::cout << "duration: " << duration << '\n';

  start = std::clock();
  std::map <uint32_t,uint32_t> memo;
  std::cout << fib_memo(45, memo) << std::endl;

  duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;
  std::cout << "duration: " << duration << '\n';

  return 0;
}


