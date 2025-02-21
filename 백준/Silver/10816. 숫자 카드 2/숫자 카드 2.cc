#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N;
	vector <int> arr(N);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		int left = 0, right = arr.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2; // 이렇게 작성해야 제일 왼쪽값이 나온다..
			if (num <= arr[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		int left_num = left;
		left = 0, right = arr.size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2; // 이렇게 작성해야 제일 왼쪽값이 나온다..
			if (num < arr[mid]) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		int cnt = right - left_num + 1;

		cout << cnt << " ";
	}
}