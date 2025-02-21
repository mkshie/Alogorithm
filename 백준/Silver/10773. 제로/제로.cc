#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <deque>
using namespace std;
//stack 자료구조는 LIFO 
//queue 자료구조는 FIFO 잊지말고 기억하자
//deque (덱) 양쪽 끝에서 둘 다 가능

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	stack <long> myStack;
	int K;
	cin >> K;
	while (K--)
	{
		int x;
		cin >> x;
		if (x == 0) {
			myStack.pop();
		}
		else
		{
			myStack.push(x);
		}
	}
	long long answer = 0;
	while (!myStack.empty())
	{
		answer += myStack.top();
		myStack.pop();
	}
	cout << answer;
	return 0;
}