#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

// sort와 stable_sort의 차이
// 기본적으로 algorithm의 sort는 quick sort로써, 기존의 순서를 보장하지 않는다
// 그러나 stable_sort는 기존의 순서를 보장한다!

bool cmp(pair<int, string> a, pair<int, string>b) {
	return a.first < b.first;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	vector<pair<int,string>> pq;
	int N;
	cin >> N;
	while (N--)
	{
		int age;
		string name;
		cin >> age >> name;
		pq.push_back({ age,name });
	}
	int k=pq.size();
	stable_sort(pq.begin(), pq.end(), cmp);

	for (auto a : pq) {
		cout << a.first << " " << a.second << "\n";
	}

	return 0;

}// ,vector<pair<int,string>>,greater<pair<int,string>>