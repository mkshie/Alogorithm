#include <iostream>
using namespace std;
int main()
{
    int x,y =0;
    cin >>x>>y;
    if (x>y)
        cout << ">";
    else if (x<y)
        cout << "<";
    else
        cout << "==";
    return 0;
    
}