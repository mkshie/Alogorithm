#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;
//stack 자료구조는 LIFO 
//queue 자료구조는 FIFO 잊지말고 기억하자

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	stack <int> myStack;
	int N;
	cin >> N;
	while (N--)
	{
		int x;
		cin >> x;
		switch (x) {
		case 1:
			int y;
			cin >> y;
			myStack.push(y);
			break;
		case 2:
			if (myStack.empty())
				cout << "-1\n";
			else
			{
				int y = myStack.top();
				cout << y << "\n";
				myStack.pop();
			}
			break;
		case 3:
			cout << myStack.size() << "\n";
			break;
		case 4:
			if (myStack.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
			break;
		case 5:
			if (myStack.empty())
				cout << "-1\n";
			else
			{
				int y = myStack.top();
				cout << y << "\n";
			}
		default:
			break;
		}
	}

	return 0;
}