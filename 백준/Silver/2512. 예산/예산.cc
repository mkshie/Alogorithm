#include <iostream>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a[100002] = {};
	a[0] = -1;
	int num = 0;
	int size = 0;
	cin >> num;
	while (num > 0)
	{
		int n;
		cin >> n;
		if (n > 0) {
			size++;
			a[size] = n;
			if (size != 1)
			{
				int ne = size;
				while (ne != 1)
				{
					if (a[ne] < a[ne / 2])
					{
						int sw = a[ne];
						a[ne] = a[ne / 2];
						a[ne / 2] = sw;
						ne = ne / 2;
					}
					else
					{
						break;
					}
				}
			}
			num--;
		}
	}

	int max = 0;
	cin >> max;  // 상한선
	int maxnum = 0;

	while (size > 0) {


		//최솟값을 빼기전에 최솟값과 남은 갯수를 비교해서 상한선을 정해둬야함

		if (a[1] > max / size)
		{
			maxnum = max / size;
			break;
		}
		else {

			max = max - a[1];

			if (maxnum < a[1])
			{
				maxnum = a[1];
			}
			a[1] = a[size];
			a[size] = 0;
			size--;
			int t = 1;
			while (t * 2 <= size)
			{
				if (a[t * 2] >= a[t * 2 + 1] && a[t * 2 + 1] != 0) {

					if (a[t] > a[t * 2 + 1])
					{
						int sw = a[t];
						a[t] = a[t * 2 + 1];
						a[t * 2 + 1] = sw;
						t = t * 2 + 1;
					}
					else
					{
						break;
					}

				}
				else if (a[t * 2] < a[t * 2 + 1] || a[t * 2 + 1] == 0)
				{
					if (a[t] > a[t * 2])
					{
						int sw = a[t];
						a[t] = a[t * 2];
						a[t * 2] = sw;
						t = t * 2;
					}
					else
					{
						break;
					}
				}

			}

		}


	}
	cout << maxnum << '\n';
	return 0;
}