#include "Widget.h"

//include Gadget.h in cpp thus reduce compile time. 
//when gadget.h modified, Widget will not need to compile again. This is PIMPL pattern
#include "Gadget.h"

struct Widget::Impl //define incomplete type in cpp
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;   
};

//in this type, completed type name should write. not just Impl form header. Widget::Impl is a completed type.
// otherwise static_asssert(point to an incomplete type) will occurs in make_unique
Widget::Widget(): pImpl(std::make_unique<Widget::Impl>()) 
{

}


Widget::~Widget() = default; //it should define here because unique pointer need to this while Widget::pImpl destruction


Widget::Widget(Widget&& rhs) = default;
Widget& Widget::operator=(Widget&& rhs) = default;

Widget::Widget(const Widget& lhs) : pImpl(std::make_unique<Widget::Impl>(*lhs.pImpl)), 
                                var1(lhs.var1), 
                                var2(lhs.var2) //deep copy
{

}

Widget& Widget::operator=(const Widget& lhs) 
{
    *pImpl = *lhs.pImpl;
    var1 = lhs.var1;
    var2 = lhs.var2;
    return *this;
}

void* Widget::getAddress()
{
    return pImpl.get();
}