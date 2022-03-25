#include <bits/stdc++.h>

using namespace std;

template<typename T>
void* myAddress(T& t) noexcept
{
    return reinterpret_cast<void*>(&t);
}

int main()
{
    double_t a = 0.0f;
    uint32_t b = 0;
    void* t = 0;  // void_t in c++17


    auto address  = myAddress(a);
    auto address2 = myAddress(b);
    
    auto address3 = myAddress(t);
    //auto address33 = myAddress(*t);

    auto address4 = reinterpret_cast<void*>(&t); // address of t
    auto address5 = reinterpret_cast<void*>(t);  // t value as address 
    

    return 0;
}