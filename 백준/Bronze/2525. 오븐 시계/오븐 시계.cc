#include <iostream>
using namespace std;

int main()
{
    int A,B;
    cin >> A >> B;
    int C;
    cin >> C;
    int D=0;
    while(C>=60)
    {
       C-=60;
       D++;
    }
    int E = C+B;
    
    if(E>=60)
    {E-=60 ; 
        D++;}
    if(A+D>23)
        cout<<A+D-24<<" "<<E;
    else
        cout<<A+D<<" "<<E;
        

    return 0;
}