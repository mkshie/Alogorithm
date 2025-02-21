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
	deque <pair<int,int>> mydeque; // 숫자,순서
	int cnt = 1;
	while (N--)
	{
		int num;
		cin >> num;
		mydeque.push_back({ num, cnt });
		cnt++;
	}
	while (!mydeque.empty())
	{
		cnt = mydeque.front().second; //순서출력
		int x = mydeque.front().first;
		cout << cnt << " ";
		mydeque.pop_front();
		if (mydeque.empty()) break;
		int y1;
		int y2;
		if (x > 0) {
			for (int i = 1; i < x; i++) {
				y1= mydeque.front().first;
				y2 = mydeque.front().second;
				mydeque.pop_front();
				mydeque.push_back({y1,y2});
			}
		}
		else
		{
			x = abs(x);
			for (int i = 0; i < x; i++) {
				y1 = mydeque.back().first;
				y2 = mydeque.back().second;
				mydeque.pop_back();
				mydeque.push_front({y1,y2});
			}
		}
	}
	return 0;
}