#include <iostream>
using namespace std;

int dn(int X)
{
	int k = X;
	int N = X;
	int sum = 0;
	int o = 0, t = 0, th = 0, f = 0;
	while (1)
	{


		if (100 <= k && k <= 999)
		{
			o = k / 100;
			k = k - (o * 100);
			t = k / 10;
			th = k % 10;
			break;
		}

		else if (1 <= k && k <= 99)
		{
			sum = 1;
			break;
		}

		else
			break;
	}

	if (100 <= N && N <= 999)
	{
		o = o - t;
		if (o == t - th)
		{
			sum = 1;
		}
	}


	return sum;
}

int main()
{
	int X = 0;
	cin >> X;
	int sum = 0;
	for (int i = 1; i <= X; i++)
	{
		sum += dn(i);
	}
	cout << sum << endl;
	return 0;
}