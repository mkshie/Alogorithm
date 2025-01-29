#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>


//LIS 최장길이 수열 문제 lower_bound 를 사용하면 더 쉽게 풀 수 있다.
//여기선 lower_bound 를 이분탐색으로 구현해보자.

using namespace std;
int N; // 배열의 크기

int LIS(vector <int>& lis, int num) {
	int left = 0, right = lis.size() - 1;
	int mid = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (lis[mid] >= num) { // 찾는값보다 mid 가 크다면?
			right = mid - 1;
		}
		else if (lis[mid] < num) {
			left = mid + 1;
		}
	}
	return left;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr; // 1. 개수 , 2 초기값
	vector<int> lis;
	cin >> N;
	int Max = 0, Min = 1000001; //벡터에서의 최소 최대
	int x = 0;
	for (int i = 0; i < N; i++) {
		cin >> x;
		arr.push_back(x);
	}
	lis.push_back(arr[0]); // 첫번째 인자는 처음에 무조건 넣어주기
	int y;
	for (int i = 1; i < N; i++) {
		y = LIS(lis, arr[i]);
		if (y == lis.size()) { lis.push_back(arr[i]); }
		else
		{
			lis[y] = arr[i];
		}
	}
	cout << lis.size() << endl;
}