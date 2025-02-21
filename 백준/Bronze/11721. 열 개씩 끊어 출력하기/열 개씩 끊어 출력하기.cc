#include <iostream>
#include <string.h>
using namespace std;

int main()

{
	char A[100];
	int length = 0;
	cin >> A;
	int B = 1;
	length = strlen(A);
	for (int i = 0; i < length; i++)
	{
		cout << A[i];
		
		if (B% 10 == 0)
		{
			cout << "\n";
		}
		B++;
	}
	return 0;
}