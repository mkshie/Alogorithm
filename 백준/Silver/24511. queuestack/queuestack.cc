#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

//stack 자료구조는 LIFO 마지막을 처음에
//queue 자료구조는 FIFO 잊지말고 기억하자
//deque (덱) 양쪽 끝에서 둘 다 가능

vector <int> inform(100001, -1);
deque <int> mydeque;

int main() {

	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, M;
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> inform[i];
	}
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		if (inform[i] == 0) {
			mydeque.push_front(x);
		}
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;
		mydeque.push_back(x);
	}
	for (int i = 0; i < M; i++) {
		cout << mydeque.front() << " ";
		mydeque.pop_front();
	}

	return 0;
}