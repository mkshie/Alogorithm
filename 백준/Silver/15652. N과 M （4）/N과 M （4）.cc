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
//순서 상관 있지만 중복 가능한 수열

void rec_che(vector <bool>& che,int cnt) {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num << " ";
		}
		cout << "\n";
			return;
	}
	for (int i = cnt; i < N + 1; i++) {
			arr.push_back(i);
			rec_che(che,i);
			arr.pop_back();
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector <bool> che(N + 1, false);
	rec_che(che,1);

}