#include <bits/stdc++.h>

using namespace std;

template<typename T>
T f(std::initializer_list<T> initList)
{ 
    T toplam;

    for(T i: initList)
    {
        toplam = toplam + i;
    }

    return toplam;
}
 

int main()
{

    cout << "done " << std::to_string(f({ 10.0f, 23.0f, 9.f })); 

    return 0;
}