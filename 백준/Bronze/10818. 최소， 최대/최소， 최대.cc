#include <iostream>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int B[A];
    int max,min;
    
    for(int i = 0 ; i < A ; i++ )
    {
        cin >> B[i];
    }
    max = B[0];
    min = B[0];
    //최대 구하는 이중 for 문
    for(int k = 1; k < A; k++)
    {
        if(B[k]>max)
            max = B[k];
        if(B[k]<min)
            min = B[k];
        
        /*for(int i = 1 ; i < A ; i++ )
        {
        
            if(B[k]>B[k+i])
                max = B[k];
            else
                max = B[k+i];
            
                 
        }
        */
    }
    
    cout << min <<" "<<max;
    return 0;
}
