#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
using namespace std;
//stack 자료구조는 LIFO 
//queue 자료구조는 FIFO 잊지말고 기억하자
//deque (덱) 양쪽 끝에서 둘 다 가능

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, K;

	cin >> N >> K;
	vector <int> vec;
	queue <int> number;
	for (int i = 1; i <= N; i++) {
		vec.push_back(i);
	}
	int idx = 0;
	K -= 1;

	while (!vec.empty()) {
		idx = (idx + K) % vec.size();
		number.push(vec[idx]);
		vec.erase(vec.begin() + idx);
	}
	cout << "<";
	for (int i = 0; i < N; i++) {
		cout <<number.front();
		number.pop();
		if (i == N - 1) continue;
		cout << ", ";
	}
	cout << ">";
	return 0;
}