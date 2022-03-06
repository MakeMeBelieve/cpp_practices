
// CPP program to illustrate assigning
// *char value to other variable 
#include <iostream>
using namespace std;
  
int main()
{
    // This initialization gives warning in C++.
    // "deprecated conversion from string constant
    // to 'char*'"
    char* str = "Hello";
  
    const char* str1 = "Hello"; // No warning
  
    // trying to modify const string literal
    // gives Runtime error
    str[1] = 'o';
    //Segmentation Fault
  
    cout << str << endl;
  
    return 0;
}