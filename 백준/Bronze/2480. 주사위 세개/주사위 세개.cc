#include <iostream>
using namespace std;

int main()
{
    int x,y,z;
  
    cin >>x>>y>>z;
  
    int c;
  
    if(x==y && y==z && x==z)
        c =1;
    else if(x==y && y!=z)
        c = 2;
    else if(x==z && y!=z)
        c = 2;
    else if(y==z && y!=x)
        c = 3;
    else
        c = 4;
    
    switch (c)
    {
        case 1:
        {cout<<10000+x*1000;
        break;}
        case 2:
        {cout<<1000+x*100; break;}
        case 3:
        {cout<<1000+y*100; break;} 
        case 4:
            {if(x>y)
                if(y>z)
                    {cout<<x*100;}
                 else if(x>z)
                     cout<<x*100;
                 else
                     cout<<z*100;
             else if(y>z)
                 cout<<y*100;
             else
                 cout<<z*100;

              break;
             }
    
    }

    return 0;
}