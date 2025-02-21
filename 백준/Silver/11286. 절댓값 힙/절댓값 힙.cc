#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue <int>  negativeq;// 양수넣는 queue
	priority_queue <int, vector<int>, greater<int>> positiveq; // 양수넣는 queue

	int N;
	cin >> N;

	while (N--) {
		int x;
		cin >> x;

		if (x != 0) {
			if (x > 0) {
				positiveq.push(x);
			}
			else negativeq.push(x);
		}
		else
		{
			if (positiveq.empty() && negativeq.empty()) { cout << "0\n"; continue; }
			//둘다 없으면 0 출력
			else if (positiveq.empty() || negativeq.empty()) {
				if (positiveq.empty()) {
					cout << negativeq.top() << "\n";
					negativeq.pop();
				}
				else
				{
					cout << positiveq.top() << "\n";
					positiveq.pop();
				}
				continue;
			}
			else
			{
				int nenum1 = negativeq.top();
				int posnum2 = positiveq.top();
				if (abs(nenum1) <= posnum2) { // 가장작은값의 절댓값이 작거나같다면
					cout << nenum1 << "\n"; // 음수 출력
					negativeq.pop(); // 음수queue 에서 삭제
				}
				else if(abs(nenum1) > posnum2) //양수가 더크다면
				{
					cout << posnum2 << "\n"; // 음수 출력
					positiveq.pop(); // 음수queue 에서 삭제
				}
			}
			
		}
	}
}