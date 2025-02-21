#include <iostream>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    int sum = A*B*C;
    int arr[10];
    int k =0;
    int T = 0;
    while(true)
    {
        if(sum<10)
        {
          arr[k] = sum;
          k++;
          break;
        }
        arr[k] = sum%10;
        k++;
        sum = sum/10;
    
    }

    //for(int i=0 ; i < k ; i++)
      //cout<<arr[i]<<endl;
    while(T <10)
    {   int count= 0;
        for(int P = 0; P < k ; P++)
        {
          if(arr[P]==T)
              count++;
        }
        cout<<count<<endl;
        T++;
    }
   
    return 0;
}

