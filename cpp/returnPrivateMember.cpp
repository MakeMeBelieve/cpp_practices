#include <bits/stdc++.h>

using namespace std;

class Widget
{
public:
    using DataType = std::vector<double>;

    DataType &data() & // for lvalue Widgets,
    {
        cout << "&data" << endl;
        return values; // return lvalue
    }
    DataType data() && // for rvalue Widgets,
    {
        cout << "&&data" << endl;
        return std::move(values); // return rvalue
    }

    uint32_t size()
    {
        return values.size();
    }

private:
    DataType values;
};

int main()
{
    Widget w;    

    //Widget::DataType& vals1 = w.data();
    auto& vals1 = w.data();

    vals1.push_back(0.5);
    vals1.push_back(0.6);
    vals1.push_back(0.7);
    
    cout << vals1.size() << endl;
    cout << w.size() << endl;

    return 0;
}