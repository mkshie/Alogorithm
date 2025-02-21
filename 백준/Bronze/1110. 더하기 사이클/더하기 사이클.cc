#include <iostream>
using namespace std;

int main()
{
  int A;
  cin >> A;
  int S;
  S=A;
  int count=0;

  
    
    while(1)
    {
      if(A<10)
      {
        A=A*10+A;
        count ++;
        if(A==S)
          {cout << count;
            break;}
      }
      else if(A==0)
      {count++; cout<<count; break;}
      
      else
      {
        int O,T,P;
        O = A/10;
        T = A%10;
        if(O+T>=10)
            P=(O+T)%10;
        else
            P=O+T;
        
        A = T*10+P;
        
        
        
        count++;
        
        if(A==S)
          {cout << count;
          break;}
      }
        
        
    }
    return 0;
}


