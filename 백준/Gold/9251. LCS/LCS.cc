#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> arr1;
vector<char> arr2;
vector<vector < int >> dp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string str1;
	cin >> str1;
	for (char a : str1) {
		arr1.push_back(a);
	}
	cin >> str1;
	for (char a : str1) {
		arr2.push_back(a);
	}
	dp.resize(arr1.size()+1,vector<int>(arr2.size()+1,0));
	int min_idx;
	for (int i = 1; i <= arr1.size(); i++) {
		for (int j = 1; j <= arr2.size(); j++) {
			if (arr1[i-1] == arr2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	cout << dp[arr1.size()][arr2.size()] << endl;
}