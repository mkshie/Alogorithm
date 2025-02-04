#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;
int N, M;
vector <int> arr;

//이전 백트래킹 문제의 응용버전
//조건을 추가하여 간단하게 구현가능.
//오름차순으로 순서가 중요

void rec_che(vector <bool>& che) {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num << " ";
		}
		cout << "\n";
			return;
	}
	for (int i = 1; i < N + 1; i++) {
			arr.push_back(i);
			che[i] = true;
			rec_che(che);
			che[i] = false;
			arr.pop_back();
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector <bool> che(N + 1, false);
	rec_che(che);

}