
#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<uint32_t> vec({5,10});
    vector<uint32_t> vec2(5,10);
    vector<uint32_t> vec3{5,10};

    cout << "vec"<< endl;
    for_each(vec.begin(),vec.end(), [](const auto& i){ cout << i << endl;});
    cout << "vec2" << endl;
    for_each(vec2.begin(),vec2.end(), [](const auto& i){ cout << i << endl;});
    cout << "vec3" << endl;
    for_each(vec3.begin(),vec3.end(), [](const auto& i){ cout << i << endl;});


    return 0;
}
