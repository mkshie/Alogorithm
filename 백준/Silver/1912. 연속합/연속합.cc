#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n;
vector <int> arr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	long long sum = 0;
	long long max = -1000;
	vector<int> point;
	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			if (sum + arr[i] > 0) sum += arr[i];
			else
			{
				sum = 0;
				if (arr[i] > max) max = arr[i];
			}
		}
		else
		{
			sum += arr[i];
			if (sum > max) max = sum;
		}
	}
	cout << max << endl;

}