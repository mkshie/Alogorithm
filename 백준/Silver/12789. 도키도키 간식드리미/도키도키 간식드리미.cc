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

bool chefunc(stack <int> Stack, queue <int> queue,int x) {
	int truenum = 1;
	while (truenum != x) {

		if (!queue.empty() && queue.front() == truenum) { queue.pop(); truenum++; }
		else if (!Stack.empty() && Stack.top() == truenum) { Stack.pop(); truenum++; }
		else if (!queue.empty()) { Stack.push(queue.front()); queue.pop(); }
		else break;

	}

	return (truenum == x);
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	stack <int> myStack; // 한명만 들어가는공간
	queue <int> myQueue; // 줄서서 대기하는공간

	int N;
	cin >> N;
	int num = N;

	while (N--) {
		int x;
		cin >> x;
		myQueue.push(x);
	}
	if (chefunc(myStack, myQueue,num)) cout << "Nice\n";
	else cout << "Sad\n";

	return 0;

}