#include <bits/stdc++.h>

using namespace std;

class Widget
{
    static vector<Widget*> WidgetList;

public:
    //Widget() = delete;
    explicit Widget(string name)
    {
        this->name = name;
        cout << "Widget created "  + name << endl;       
        WidgetList.emplace_back(this);
    }
    ~Widget() 
    { 
        cout << "Widget deleted " + name << endl;
        for(std::vector<Widget*>::iterator it = WidgetList.begin(); it != WidgetList.end(); ++it)
        {
            if(*it == this)
            {
                WidgetList.erase(it);
                break;
            }
        }

    }

    //Widget(const Widget &) = delete;            // no copy constructor
    //Widget &operator=(const Widget &) = delete; // no copy assignment

    //Widget(Widget &&) = delete;            // no move constructor
    //Widget &operator=(Widget &&) = delete; // no move assignment

    void DoSomething() { cout << name << endl; }
    static void ProcessWidgetList()
    {
        for_each(WidgetList.begin(), WidgetList.end(), [](auto &w)
                 { w->DoSomething(); });
    }

private:
    string name{"noName"};
};

vector<Widget*> Widget::WidgetList;

int main()
{
    {
        // Widget *w = new Widget("1"); // raw pointer
        //  shared_ptr<Widget> shared1(w);
        //  shared_ptr<Widget> shared2(w);
        //  there are 2 control Block of w, so 2 time destructor calls. error
    }

    {
        Widget *w = new Widget("0"); // raw pointer
        shared_ptr<Widget> shared1(w);
        shared_ptr<Widget> shared2(shared1);
        // shared 2 is not a new pointer
        // it is using same control block with shared1
    }

    {
        unique_ptr<Widget> s1(new Widget("1"));
        unique_ptr<Widget> s2(new Widget("2"));

        Widget::ProcessWidgetList();        
    }

    return 0;
}
