#include <iostream>
using namespace std;

int main()
{
    int A;
    bool b;
    cin >> A;
    if(A%4==0 && A%100!=0)
        b = true;
    else if(A%400==0)
        b = true;
    else
        b=false;
    
    if(b)
        cout<<1;
    else
        cout<<0;
    
    return 0;
}