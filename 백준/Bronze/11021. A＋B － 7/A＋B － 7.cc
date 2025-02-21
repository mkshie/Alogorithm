#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int A[T];
    int B[T];
    for(int i=0;i<T;i++)
    {
        cin >>A[i] >>B[i];
    }
    
    for(int k=0;k<T;k++)
    {
        cout<<"Case #"<<k+1<<": "<<A[k]+B[k]<<endl;
    }
        
    return 0;
}