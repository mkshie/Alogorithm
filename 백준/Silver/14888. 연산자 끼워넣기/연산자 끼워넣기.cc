#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_num = -1000000000, min_num = 1000000000;
int N;
int result;
vector <int> num;
vector <int> str(4, 0); //+ - * /

void rec(int cnt) {
	if (cnt == N) {
		if (max_num < result) max_num = result;
		if (min_num > result) min_num = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (str[i] != 0) {
			int back_num = result;
			switch (i)
			{
			case 0 :
				result += num[cnt];
				break;
			case 1:
				result -= num[cnt];
				break;
			case 2:
				result *= num[cnt];
				break;
			case 3:
				result /= num[cnt];
				break;
			}
			str[i] -= 1;
			rec(cnt+1);
			str[i] += 1;
			result = back_num;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	num.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> str[i]; // 사칙연산 개수
	}
	result = num[0];
	rec(1);
	cout << max_num << "\n" << min_num;

}
