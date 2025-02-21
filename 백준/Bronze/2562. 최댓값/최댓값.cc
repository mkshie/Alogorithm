#include <iostream>
using namespace std;

int main()
{
    int A[9];
    for(int i = 0 ; i < 9 ; i++)
    {
        cin >> A[i];
    }
    
    int max = A[0];
    int count = 1; 
    
    for(int k = 1 ; k < 9 ; k++)
    {
        if(max < A[k])
        {max = A[k]; count = k+1;}
    }
    
    cout << max <<endl<< count;
    return 0;
}
