#include <iostream>

class Test 
{
    uint32_t value;
    
public:
    Test(uint32_t v) { this->value = v;}
    uint32_t getValue() const { return value; }
};

int main()
{
    // The qualifier const can be applied to the declaration of any variable 
    // to specify that its value will not be changed.
    // const keyword applies to whatever is immediately to its left.
    // If there is nothing to its left, it applies to whatever is immediately to its right. 
    
    Test testNonConstant(10);
    std::cout << testNonConstant.getValue() << std::endl;
    
    const Test testConstant(20); //getValue shall be const 
    std::cout << testConstant.getValue() << std::endl;
    
    ////////////////////////////////////////////////////
    
    //  “const char *” is a (non-const) pointer to a const char.
    // pointer can change but pointed data cannot
    char text1[] = "text1";
    char text2[] = "text2";
    
    const char* p = text1;
    std::cout << p << std::endl;
    
    p = text2; // p changed
    std::cout << p << std::endl;
    
    //p[0] = 'X'; // <-- error: assignment of read-only location ‘* p’
    std::cout << p << std::endl;
    
    //There is no difference between const char *p and char const *p as
    //both are pointer to a const char and position of ‘*'(asterik) is also same. 
    
    //////////////////////////////////////////////////////////////////////
    
    //char *const ptr : This is a constant pointer to non-constant character. 
    //You cannot change the pointer p, but can change the value pointed by ptr. 
    
    char text4[] = "text4";
    char text5[] = "text5";
    
    char* const Pointer = text4;
    
    std::cout << Pointer << std::endl;
    
    //Pointer = text5; //<--- error: assignment of read-only variable ‘Pointer’
    Pointer[0] = 'x'; //pointed value can change but pointer itself its const
    
    std::cout << Pointer << std::endl;
    
    //////////////////////////////////////////////////////////////////////
    
    // const char * const ptr : This is a constant pointer to constant character.
    // You can neither change the value pointed by ptr nor the pointer ptr. 
    
    char text6[] = "text6";
    char text7[] = "text7";
    
    const char* const pointerTest = text6;
    
    //pointerTest = text7; // <-- error: assignment of read-only variable ‘pointerTest’
    //pointerTest[0] = 'X'; // <-- error: assignment of read-only location ‘*(const char*)pointerTest’
    
    std::cout << pointerTest << std::endl;
    
    //////////////////////////////////////////////////////////////////////

    char arr[] = "geeks"; // 5 char and 1 termination added by compiler /0
  
    std::cout << sizeof(arr) << std::endl;
    
    char arr2[]= {'g', 'e', 'e', 'k', 's'}; //there is no termination /0
    
    std::cout << sizeof(arr2) << std::endl;
    
    // Works in C, but compilation error in C++
    //char arr3[5] = "geeks"; //there is no termination /0 fixed size
    // error: initializer-string for array of chars is too long [-fpermissive]
    
    //std::cout << sizeof(arr3) << std::endl;
    
    
    
    return 0;
}









