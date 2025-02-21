#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		int b = 0; // 인원
		cin >> b;
		int sum = 0; // 값의 합
		int* v = new int[b];
		for (int k = 0; k < b; k++)
		{
			int sc;
			cin >> sc;
			v[k] = sc;
			sum += sc;
		}
		int av = sum / b;
		int ch = 0;
		for (int k = 0; k < b; k++)
		{
			if (v[k] > av)
			{
				ch++;
			}
		}
		double kk = ch / (double)b * 100;
		cout << fixed;
		cout.precision(3);
		cout << kk << "%" << endl;
	}
	return 0;
}
