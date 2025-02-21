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
	stack <char> myStack; // ( 
	string str1;
	string che1 = "";
	do
	{
		che1 = "yes";
		getline(cin, str1);
		if (str1 == ".") break;
		for (char a : str1) {
			if (a == '(') myStack.push(a);
			else if (a == '[') myStack.push(a);

			if (a == ')') {
				if (myStack.empty() || myStack.top() != '(') { che1 = "no"; break; }
				myStack.pop();
			}
			else if (a == ']') {
				if (myStack.empty() || myStack.top() != '[') { che1 = "no"; break; }
				myStack.pop();
			}
		}
		if (myStack.empty() && che1=="yes") che1 = "yes";
		else che1 = "no";
		cout << che1 << "\n";
		while (!myStack.empty()) {
			myStack.pop();

		}
	} while (str1 != ".");




}
