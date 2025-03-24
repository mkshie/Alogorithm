#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	vector<int> dp(N, 1);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if(arr[i] > arr[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
	}

	int lis = *std::max_element(dp.begin(), dp.end());
	cout << lis;
}