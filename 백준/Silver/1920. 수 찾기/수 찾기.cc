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
	vector <int> arr(N); //첫번째 인자는 크기 두번째인자는 초기값
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
			int mid = (left + right) / 2;
			if (num <= arr[mid]) { // 작다면?
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		if (left != arr.size() && arr[left] == num) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;

}