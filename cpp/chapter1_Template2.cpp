#include <bits/stdc++.h>

using namespace std;

#define assertm(exp, msg) assert(((void)msg, exp))

void authenticateUser()
{

}

template<typename Container, typename Index> 
decltype(auto) authAndAccess(Container&& c, Index i) noexcept
{
    authenticateUser();
    assertm(c.size() > i, "authAndAccess out of range exception");
    return std::forward<Container>(c)[i];
}
 

int main()
{

    std::vector<uint32_t> vec;
    vec.push_back(15);
    vec.push_back(10);
    vec.push_back(2);

    for_each(vec.begin(),vec.end(),[](const auto& i){cout << to_string(i) << " " ;});

    uint32_t& ref =  authAndAccess(vec, 1);

    cout << hex << ref << endl;
    cout << hex << &ref << endl;

    uint32_t& ref2 =  authAndAccess(vec, 12);

    cout << hex << ref2 << endl;
    cout << hex << &ref2<< endl;

    for_each(vec.begin(),vec.end(),[](const auto& i){cout << to_string(i) << " " ;});

    return 0;
}