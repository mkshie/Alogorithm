#include <iostream>
#include <string>
using namespace std;

enum MyEnum
{
	a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6, h = 7, i = 8, j = 9, k = 10, l =
	11, m = 12, n = 13, o = 14, p = 15, q = 16, r = 17, s = 18,
	t = 19, u = 20, v = 21, w = 22,x = 23, y = 24, z = 25
};

int main()
{
	string str1 = "";
	cin >> str1;

	int arr[26];



	for (int i = 0; i < 26; i++)
	{
		arr[i] = -1;
	}

	for (int i = 0; i < str1.size(); i++)
	{
		if (arr[str1[i]-97] == -1)
		{
			arr[str1[i] - 97] = i;
		}
		else
		{
			
		}
	}

	for (int i = 0; i < 26; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;


}