#include <iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;
	int N;
	cin >> N;
	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		int a = 0, b = 0;
		cin >> a;
		cin >> b;
		sum += a * b;
	}

	if (sum == X)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}