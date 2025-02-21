#include <iostream>
#include <string>
using namespace std;


int dn(int X)
{
	int sum = X;
	int k = X;
	int o = 0, t = 0, th = 0, f = 0;
	while (true)
	{
		if (1000 <= k <= 9999)
		{
			 o= k / 1000;
			 k = k - (o*1000);
			 t = k / 100;
			 k = k - (t * 100);
			 th = k / 10;
			 f = k % 10;
			 break;
		}

		else if (100 <= k <= 999)
		{
			o = k / 100;
			k = k - (o * 100);
			t = k / 10;
			th = k % 10;
			break;
		}

		else if (10 <= k <= 99)
		{
			o = k / 10;
			t = k % 10;
			break;
		}

		else
		{
			o = k;
			break;
		}
	}

	sum = sum + o + t + th + f;
	return sum;
}

int main()
{
	int a[20000] = {};
	a[0] = 1;

	for (int i = 0; i < 9990; i++)
	{
		a[dn(i)] += 1;
	}
	for (int i = 0; i < 10001; i++)
	{
		if (a[i] == 0)
		{
			cout << i << endl;
		}
	}
	return 0;
}