#include <iostream>
#include <vector>

using namespace std;
int N;

int cnt = 0;
vector <int> chess; //idx 는 row data 는 col

bool is_safe(int row, int col) { // 같은 열과 대각선에 있는지 확인
	for (int i = 0; i < row; i++) {
		if (col == chess[i] || abs(row - i) == abs(col - chess[i])) return false;
	}
	return true;

}


void rec_che(int row) {
	if (row == N) {
		cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (is_safe(row,i)) {
			chess[row] = i;
			rec_che(row + 1);
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	chess.resize(N);
	rec_che(0);
	cout << cnt;

}
