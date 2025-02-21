#include <iostream>
#include <vector>

using namespace std;

long long cnt = 0;
long long K = -1;
int N;
int arr[500000];

void merge(int, int, int);


void mergeSort(int left, int right) {
	if (cnt == K) return;
	if (left >= right) {
		return;
	}
	int mid = (left + right) / 2;
	mergeSort(left, mid);
	mergeSort(mid + 1, right);
	merge(left, mid, right);
}

void merge(int left, int mid, int right) {
	int i = left, j = mid + 1, t = 0; // i 는 왼쪽배열의 시작지점 , j 는 오른쪽배열의 시작지점
	//t 는 새로 담는 배열의 시작지점.
	int* tmp = new int[right - left + 1];
	while (i<=mid && j <=right) {
		if (arr[i] <= arr[j]) tmp[t++] = arr[i++];
		else tmp[t++] = arr[j++];
	}
	while (i <= mid)
		tmp[t++] = arr[i++];
	while (j <= right)
		tmp[t++] = arr[j++];
	i = left, t = 0;
	while (i <= right) { //이제 다시 되돌리는 작업
		arr[i++] = tmp[t++];
		cnt++;
		if (cnt == K) { cout << arr[i-1]; return; }
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	mergeSort(0, N - 1);
	if (cnt < K) cout << -1;

}