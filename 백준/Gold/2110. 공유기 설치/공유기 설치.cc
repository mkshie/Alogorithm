#include <iostream>
#include <algorithm>

using namespace std;

int N, C; // N 집의 개수 , C 공유기 개수
int Narr[200000] = { 0 };

bool Can(int x) { // x 는 간격임
	int cnt = 1;
	int last_house = Narr[0]; // 첫번째 집은 무조건 설치한다는걸 가정
	for (int i = 1; i < N; i++) {
		if (Narr[i] - last_house >= x) {
			cnt++;
			last_house = Narr[i];
		}
	}
	return cnt >= C;

}

int binsearch(int low, int high) {
	int max = 0;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (Can(mid)) { //mid 값으로 설치가 가능한것이니 더 큰 값을 해보자.
			if (max < mid) max = mid;
			low = mid + 1;
		}
		else
		{
			// 설치가 불가능하니 더 작은값을 시도해보자.
			high = mid - 1;
		}
	}
	return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> Narr[i];
	}
	int n = sizeof(Narr) / sizeof(Narr[0]);
	sort(Narr, Narr + N);
	cout << binsearch(1, Narr[N - 1] - Narr[0]);

	return 0;
}