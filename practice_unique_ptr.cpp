#include <iostream>
#include <memory>
#include <vector>
using namespace std;
  
class A {
public:
    void show()
    {
        cout << "A::show()" << endl;
    }
};

unique_ptr<A> fun()
{
    unique_ptr<A> ptr(new A);

    /* ...
       ... */

    return ptr;
}
  
int main()
{
   // unique_ptr<A> p1(new A);
   // unique_ptr<vector<uint32_t>> p44 = unique_ptr<vector<uint32_t>>(new vector<uint32_t>(10,0));
    
   // std::cout << (*p44)[0] << std::endl;
   // std::cout << p44.get() << std::endl;
    
    unique_ptr<A> p55;
    
    fun();
    p55 = fun();
    
    p55->show();
    
    /*
    
    p1->show();
  
    // returns the memory address of p1
    cout << p1.get() << endl;
  
    // transfers ownership to p2
    unique_ptr<A> p2 = move(p1);
    p2->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
  
    // transfers ownership to p3
    unique_ptr<A> p3 = move(p2);
    p3->show();
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    cout << p3.get() << endl;
  */
    return 0;
}