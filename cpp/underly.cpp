#include <bits/stdc++.h>

using namespace std;

template <typename T>
constexpr auto getEnumUnderlying(T enumarator)
{
    return static_cast<underlying_type_t<T>>(enumarator);
}

int main()
{
    std::array<int, 3> a2 = {1, 2, 3};

    vector<tuple<string, uint32_t, string>> student;
    
    enum class legend
    {
        name,
        age,
        description
    };

    student.push_back(make_tuple(string("Mike Tyson"), (uint32_t)65, string("Boxer")));
    student.push_back(make_tuple(string("Harry Potter"), (uint32_t)30, string("Mage")));

    auto display = [](auto& tuple) {    
        cout << get<getEnumUnderlying(legend::name)>(tuple) << endl;
        cout << to_string(get<getEnumUnderlying(legend::age)>(tuple)) << endl;
        cout << get<getEnumUnderlying(legend::description)>(tuple) << endl;
    };

  
    // system cmd commands
    //system("pause");

    for_each(student.cbegin(), student.cend(), display);

    return 0;
}