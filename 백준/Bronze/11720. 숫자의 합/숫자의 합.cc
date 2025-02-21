#include <iostream>
using namespace std;

int main() 
{
	int A{ 0 }, B{ 0 }, D{ 0 };
	char C[105]="";
	cin >> A;
	cin >> C;
	for ( B ; B < A; B++)
	{
		D += C[B]-'0';

	}
	cout<< D;
	return 0;
}