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
	int N;
	cin >> N;
	deque <int> myDeque;

	for (int i = 1; i <= N; i++) {
		myDeque.push_back(i);
	}
	while (myDeque.size() != 1) {
		myDeque.pop_front();
		myDeque.push_back(myDeque.front());
		myDeque.pop_front();
	}

	cout << myDeque.front() << "\n";
	return 0;
}