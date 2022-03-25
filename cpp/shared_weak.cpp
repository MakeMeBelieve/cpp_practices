#include <bits/stdc++.h>

#include <crtdbg.h>

using namespace std;

class Widget {
public:
    Widget(int i)
    {

    }

    void read()
    {
        cout << "read" << endl;
    }


};

int main()
{
    //Windows API
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    unique_ptr<Widget> unique(make_unique<Widget>(1));
    unique_ptr<Widget> unique2(new Widget(1));
    
    unique->read();
    unique2->read();

    initializer_list<int> param = {1,2,3,4};

    auto p = make_unique<vector<int>>(param); // forwarding initializer_list     
    auto p2 = make_unique<vector<int>>(initializer_list<int>({1,2,3,4,5}));

    auto p = make_unique<vector<int>>(1,2); // parantes mean is differnt thrn bracet

    return 0;
}