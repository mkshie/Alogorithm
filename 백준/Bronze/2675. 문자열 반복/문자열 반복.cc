#include <iostream>
#include <string>
using namespace std;

int main()
{
	int num = 0;
	cin >> num;
	for (int i=0;i<num;i++)
	{
		int c = 0;
		cin >> c;
		string str1;
		cin >> str1;
		for (int k = 0; k < str1.size(); k++)
		{
			for (int p = 0; p < c; p++)
			{
				cout << str1[k];
			}
		}
		cout << "\n";
	}
	return 0;
}