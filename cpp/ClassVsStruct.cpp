#include <bits/stdc++.h>

using namespace std;

class BaseClass
{
public:
    BaseClass() : privateVal(10), protectedVal(11) {}
    ~BaseClass() = default;

    virtual void testVirtual() { cout << "BaseClass virtual method called" << endl;}

private:
    uint32_t privateVal;

protected:
    uint32_t protectedVal;
};

class DerivedClass : public BaseClass
{
    int val1;

public:
    DerivedClass() : val1{-1} {}
    void show(){cout << to_string(val1) << endl;}
    void showBaseProtected() {cout << to_string(protectedVal) << endl;}
    ~DerivedClass() = default;

    void testVirtual() override { cout << "DerivedClass method called" << endl;}
    
};

struct BaseStruct 
{
public:
    BaseStruct() : privateVal(10), protectedVal(11) {}
    ~BaseStruct() = default;

    virtual void testVirtual() { cout << "BaseStruct virtual method called" << endl;}

private:
    uint32_t privateVal;

protected:
    uint32_t protectedVal;
};

struct DerivedStruct: public BaseStruct
{
private:
    int val1;

public:
    DerivedStruct() : val1{-1} {}
    void show(){cout << to_string(val1) << endl;}
    void showBaseProtected() {cout << to_string(protectedVal) << endl;}
    ~DerivedStruct() = default;

    
    void testVirtual() override { cout << "DerivedStruct method called" << endl;}
};


int main()
{
    DerivedClass  cls;
    DerivedStruct str;

    cls.show();
    str.show();

    // error: 'int DerivedStruct::val1' is private within this context
    //cls.val1 = 3;
    //str.val1 = 4;
   
    cls.showBaseProtected();
    str.showBaseProtected();

    unique_ptr<BaseClass> pCls = make_unique<DerivedClass>();
    unique_ptr<BaseStruct> pStr = make_unique<DerivedStruct>();

    pCls->testVirtual();
    pStr->testVirtual();

    //there is only one difference struct elements are public in default. that's it. !

    return 0;

}