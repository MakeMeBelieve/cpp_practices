#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <bits/stdc++.h>

// to prevent recursive include in order to reduce compile time
// do not include Gadget.h at header.
// instead of that create a pointer to implementation (pimpl)

class Widget
{
public:
    Widget();
    ~Widget(); // just declaration

    Widget(Widget&& rhs); // declarations only 
    Widget& operator=(Widget&& rhs); // 

    Widget(const Widget& lhs); // declarations only becuase it needs a deep copy not shallow.
    Widget& operator=(const Widget& lhs); // 

    void* getAddress();

private:
    struct Impl; //just declaration, this is an incomplete type !
    std::unique_ptr<Impl> pImpl;

private:
    uint32_t var1;
    std::vector<uint32_t> var2;


};

#endif