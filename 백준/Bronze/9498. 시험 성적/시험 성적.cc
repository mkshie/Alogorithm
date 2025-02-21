#include <iostream>
using namespace std;

int main()
{
    int X;
    cin >> X;
    if(90<=X && X<=100)
      cout<<"A";
    else if(80<=X&& X<=90)
      cout<<"B";
    else if(70<=X &&X<=79)
      cout<<"C";
    else if(60<=X &&X<=69)
      cout<<"D";
    else
      cout<<"F";
    return 0;
}