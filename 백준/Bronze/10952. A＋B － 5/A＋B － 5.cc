#include <iostream>
using namespace std;

int main()
{
    int count=0;
    int i=0;
    int A[100];
    int B[100];
    bool Q=true;
    while(Q)
    {
        cin >>A[i] >>B[i];
        if(A[i]==0 && B[i]==0)
            Q=false;
        count++;
        i++;
        
    }
    
    for(int k=0;k<count-1;k++)
    {
        cout<<A[k]+B[k]<<'\n';
    }
        
    return 0;
}
