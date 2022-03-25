#include <bits/stdc++.h>

#include "Widget.h"

using namespace std;

int main()
{
    Widget w;

    Widget w2(w);

    if(w.getAddress() == w2.getAddress() )
        cout << "swallow copy" << endl;
    else
        cout << "deep copy" << endl;
        
        
   return 0;
}