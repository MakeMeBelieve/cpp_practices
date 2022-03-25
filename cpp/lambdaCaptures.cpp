#include <bits/stdc++.h>

using namespace std;

using FilterContainer = vector<function<bool(int)>>;

FilterContainer filters;

function<void(int)> DispatchFilter = [](int value)
{
    for (int i = 0; i < filters.size(); i++)
    {
        cout << (filters[i](value) ? "ok" : "fail") << endl;
    }

    filters.clear();
};

class Widget
{
public:
    Widget(int divisor) : divisor(divisor) { cout << "Widget created" << endl; }
    ~Widget()
    {
        cout << "deleted" << endl;
    }

    // add a entry to filter
    void addFilter() const;

    // add a entry to filter
    void addFilter2() const;

    // add a entry to filter
    void addFilter3() const;

    // mutable closure
    void addFilterConst() const;

private:
    int divisor;
};

void Widget::addFilter() const
{
    // this divisor is an reference this->divisor so if this destructed, closure have dangle pointer
    filters.push_back(
        [=](int value)
        {cout << "divisor value :" + to_string( divisor ) << endl; return value % divisor == 0; });
}

void Widget::addFilter2() const
{
    // closure only captures as copy non-static elements others will be reference
    // [=] captures nothing, because there is no local variable.
    static int divisor_static = divisor;

    filters.push_back(
        [=](int value)
        {cout << "divisor value :" + to_string( divisor_static ) << endl; return value % divisor_static == 0; });

    // value changed after clousure
    divisor_static = rand() * 100;
}

void Widget::addFilter3() const
{
    // copy divisor_local into closure so divisor can destruct.
    int divisor_local = divisor;

    filters.push_back(
        [=](int value)
        {cout << "divisor value :" + to_string( divisor_local ) << endl; return value % divisor_local == 0; });

    // direct copy of divisor_local to div is also possible
    /*
    filters.push_back(
        [div = divisor_local](int value)
        {cout << "divisor value :" + to_string( div ) << endl; return value % div == 0; });
    */
}

void Widget::addFilterConst() const
{    
      int divisor_local = divisor;

    filters.push_back(
        [=](int value) 
        {cout << "divisor value :" + to_string( divisor_local ) << endl; 
        //divisor_local = 10; //error: assignment of read-only variable 'divisor_local'
        //divisor = 10; //error: assignment of member 'Widget::divisor' in read-only object      
        return value % divisor_local == 0; });

    filters.push_back(
        [=](int value) mutable
        {cout << "divisor value :" + to_string( divisor_local ) << endl; 
        divisor_local = 10; //valid with mutable. copied variables are const
        //divisor = 10; //error: assignment of member 'Widget::divisor' in read-only object      
        return value % divisor_local == 0; });

    filters.push_back(
        [myDivisor = divisor](int value) mutable
        {cout << "divisor value :" + to_string( myDivisor ) << endl; 
        myDivisor = 10; //valid with mutable. copied variables are const
        //divisor = 10; //error: assignment of member 'Widget::divisor' in read-only object      
        return value % myDivisor == 0; });
}

int main()
{
    int value = 100;
    int divisor = 10;

    // try 1
    shared_ptr<Widget> w = make_shared<Widget>(divisor);
    w->addFilter();
    w.reset(); // destruct Widget
    DispatchFilter(value);

    // try 2
    w = make_shared<Widget>(divisor);
    w->addFilter2();
    w.reset(); // destruct Widget
    DispatchFilter(value);

    // try 3
    w = make_shared<Widget>(divisor);
    w->addFilter3();
    w.reset(); // destruct Widget
    DispatchFilter(value);

    return 0;
}
