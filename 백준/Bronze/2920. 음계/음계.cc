#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a[8]{};
	for (int i = 0; i < 8; i++)
	{
		cin >> a[i];
	}
	int check = 0;
	for (int i = 1; i < 8; i++)
	{
		if (a[i] - a[i - 1] == 1)
		{
			//keep~
		}
		else if (a[i] - a[i - 1] == -1)
		{
			//keep~
		}
		else
		{
			check = -1;
		}
	}
	if (check == 0)
	{
		if (a[0] == 1)
			cout << "ascending";
		else
			cout << "descending";
	}
	else
	{
		cout << "mixed";
	}

	return 0;
}