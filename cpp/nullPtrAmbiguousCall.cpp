#include <bits/stdc++.h>

using namespace std;


void f(int32_t) {cout << "called f(int32_t)"<< endl;};
void f(bool) {cout << "called f(bool)"<< endl;};
void f(void*) {cout << "called f(void*)"<< endl;}

int main()
{
    f(0);
    //f(NULL); //call of overloaded 'f(NULL)' is ambiguous
    f(nullptr);

    f((void*)0);

    f(reinterpret_cast<void*>(0));

    //f(0L); //call of overloaded 'f(long int)' is ambiguous

    //f(0.f); //call of overloaded 'f(float)' is ambiguous

    return 0;
}