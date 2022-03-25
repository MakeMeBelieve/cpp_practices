#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<uint32_t> v;

    uint32_t a = 2;

    v.push_back(1); //r value push_back add a move operation
    v.push_back(a); //l value

    v.emplace_back(move(1)); //r value you have add move otherwise because of refence collapsing, it deduce as
    v.emplace_back(a); //l value


    for_each(v.begin(), v.end(), [](auto& i){cout << i << endl;});

    return 0;
}

/*
template <class T, class Allocator = allocator<T> >
class vector {
public:
    ...
    void push_back(T&& x);       // fully specified parameter type ⇒ no type deduction;
    ...                          // && ≡ rvalue reference
};

template <class T, class Allocator = allocator<T> >
class vector {
public:
    ...
    template <class... Args>
    void emplace_back(Args&&... args); // deduced parameter types ⇒ type deduction;
    ...                                // && ≡ universal references
};


*/