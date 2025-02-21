#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int B=A-1;
    for(int i=1;i<A+1;i++)
    {
        for(int k=1;k<B+1;k++)
        {
            cout<<" ";
            
        }
        B-=1;
        
        for(int c=1;c<i+1;c++)
        {
            cout<<"*";
        }
        cout<<endl;
                
    
    }
    return 0;
}
