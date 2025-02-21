#include <iostream>

using namespace std;

int treeh[1000000] = { 0 };
unsigned int  tsize ,  num; // tsize 는 나무의 수 num 은 가져가려고하는 나무의 길이

//첫번째와 맨 마지막의 숫자를 가지고 비교를 하면서 점점 값을 찾아가면 해결되는 쉬운 문제.

int bisearch(long i,long j ,long k ) { //i가 시작 , j 가 중간값 , k 마지막값
	int max = 0;
	bool che = false;
	while (i <= k) {
		long long sum = 0;
		j = i + (k-i) / 2;
		for (int p = 0; p < tsize; p++) {
			if (treeh[p] > j) {
				sum += treeh[p] - j;
			}
		}
		if (sum == num) {
			che = true;
			return j;
		}
		else if (num > sum) { // 합계가 더 작음 나무의 길이를 줄여야됨
			k = j - 1;
		}
		else {
			i = j + 1;
			if(max<j) max = j;
		}
	}

	if (!che) return max;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	// 문제의 조건은 적어도 M 미터의 나무를 가져가기 위해서 절단기에 설정할 수 있는 최챗값을 구하는 문제

	cin >> tsize >> num;

	for (int i = 0; i < tsize; i++) {
		cin >> treeh[i];
	}

	cout << bisearch(0,500000000,1000000000); // 인자로 나무의 수와 내가 찾고있는 값을 알려줌

	return 0;
}