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
	deque <int> mydeque;

	while (N--) {
		int x;
		cin >> x;
		int num;
		switch (x)
		{
		case 1:
			cin >> num;
			mydeque.push_front(num);
			break;
		case 2:
			cin >> num;
			mydeque.push_back(num);
			break;
		case 3:
			if (mydeque.empty()) cout << -1 << "\n";
			else {
				cout << mydeque.front() << "\n";
				mydeque.pop_front();
			}
			break;
		case 4:
			if (mydeque.empty()) cout << -1 << "\n";
			else {
				cout << mydeque.back() << "\n";
				mydeque.pop_back();
			}
			break;
		case 5:
			cout << mydeque.size() << "\n";
			break;
		case 6:
			if (mydeque.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 7:
			if (mydeque.empty()) cout << -1 << "\n";
			else cout << mydeque.front() << "\n";
			break;
		case 8:
			if (mydeque.empty()) cout << -1 << "\n";
			else cout << mydeque.back() << "\n";
			break;
		default:
			break;
		}
	}

	return 0;
}