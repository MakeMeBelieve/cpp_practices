#include <bits/stdc++.h>

using namespace std;

std::vector<bool> features(const uint32_t& w)
{
    vector<bool> vec;
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    vec.push_back(w);
    return vec;
}

void process(const uint32_t& w, bool feature)
{

}

int main()
{

    cout << __cplusplus << endl;

    const uint32_t a = 1;    

    bool high = (features(a))[5];
    auto high2 = (features(a))[5];
    auto highPriority = static_cast<bool>(features(a)[5]);
    
    assert(high == high2);

    process(a, high);

    return 0;
}