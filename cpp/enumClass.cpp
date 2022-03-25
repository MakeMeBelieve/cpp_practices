#include <bits/stdc++.h>

using namespace std;

int main()
{   
    enum class Color {red, blue, green}; //in scope
    
    enum Size {S, M, L, XL, XXL}; // scopeless

    //auto clothColor = red; //need scope
    auto clothColor = Color::red;

    auto clothSize = S; // fine
    auto clothSize2 = Size::S; // also fine

    //prefer enum class over enum

    //instead of typedef use using keyword.
    using VS = vector<string>;
    
    VS book;

    book.push_back("sentences");


    
    return 0;
}