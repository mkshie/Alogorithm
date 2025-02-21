#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, answer, min;
	min = 9999;
	answer = -1;
	cin >> N;
	int x, y; // x 는 몫 y 는 나머지
	x = N / 5;
	y = N % 5;
	// 숫자들을 5로 나눈다음 만약 나누어 떨어진거라면??
	int num1 = N - (5 * x);
	int x1, y1; // 몫 , 나머지
	x1 = num1 / 3;
	y1 = num1 % 3;
	while (1) {
		if (y == 0 || y1 == 0)// 둘의 나머지가 둘다 0이라면 만들수있음
		{
			if (x + x1 < min) min = x + x1; //최솟값 작으면 교체
		}
		if (x1 == N / 3) {
			if (min < 9999)
				answer = min;
			break;
		}
		x--;
		num1 = N - (5 * x);
		x1 = num1 / 3;
		y1 = num1 % 3;
	}
	cout << answer << "\n";

	return 0;
}