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
	stack <char> myStack;
	bool che = true;

	int T;
	int cnt;
	cin >> T;
	while (T--)
	{
		string str1;
		cin >> str1;
		che = true;
		cnt = 0;
		for (char a : str1) {
			if (a == ')') {
				if (myStack.empty()) { // 비어있는데 ) 라면 그냥 false
					che = false;
					break;
				}
				else
				{
					myStack.pop();
				}
			}
			else
			{
				myStack.push(a);
			}
		}
		if (!myStack.empty()) che = false;
		
		if (che) cout << "YES\n";
		else cout << "NO\n";

		while (!myStack.empty()) myStack.pop();
	}

	return 0;
}
