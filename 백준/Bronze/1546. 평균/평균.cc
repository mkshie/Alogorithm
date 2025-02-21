#include <iostream>
using namespace std;

int main()
{
	int c;
	cin >> c;  // 과목의 개수
	double* a = new double[c];
	int b;
	int max=0;
	int check = 0;
	double sum = 0;

	for (int i = 0; i < c; i++) // 과목 입력 받기
	{
		cin >> b;
		a[i] = b;
		if (max < b)
		{
			max = b;
			check = i;
		}
	}

	for (int i = 0; i < c; i++)
	{
		if (check != i)
		{
			sum += a[i] / a[check] * 100;
		}
		else
		{
			sum += 100;
		}
	}

	sum = sum / c;

	cout << sum;



	return 0;
}