#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;
int N;
vector<string> arr;


void rec_set(int left, int right) {
	int gap = right - left;
	if (gap < 3) return;
	gap = gap / 3;
	rec_set(left, left + gap);
	rec_set(left + gap * 2, right);
	for (int i = 0; i < gap; i++) {
		arr[left + i + gap] = " ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> N) {
		int cnt = 1;
		int arr_size = 1;
		while (cnt <= N) {
			arr_size = arr_size * 3;
			cnt++;
		}
		for (int i = 0; i < arr_size; i++) {
			arr.push_back("-");
		}
		rec_set(0, arr_size);
		for (size_t i = 0; i < arr.size(); i++) {
			cout << arr[i];
		}
		cout << "\n";
		arr.clear();
	}

}