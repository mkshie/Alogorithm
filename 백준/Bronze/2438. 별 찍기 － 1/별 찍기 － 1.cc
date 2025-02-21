#include <iostream>
using namespace std;
int main()
{
	int a = 0, b = 1;
	cin >> a;
	for ( int i = 0; i < a; i++)
	{
		for (int c = 0; c < b; c++)
		{
			cout << "*";
			
		}
		cout << endl;
		b++;
	}
	return 0;
}