#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>


using namespace std;
vector<vector<int>> arr(10, vector<int>(10, 0));
vector<pair<int, int>> blank;
int siz = 0;
bool che = false;
bool c1[10][10];
bool c2[10][10];
bool c3[10][10];


int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

//bool can(int row, int col, int num) {
//	for (int i = 0; i < 9; i++) {
//		if (num == arr[row][i]) return false;
//	}
//	for (int i = 0; i < 9; i++) {
//		if (num == arr[i][col]) return false;
//	}
//	//3x3 블록 검사.
//	int rownum = row / 3, colnum = col / 3;
//	for (int i = 3 * rownum; i < 3 * rownum + 2; i++) {
//		for (int j = 3 * colnum; j < 3 * colnum + 2; j++) {
//			if (num == arr[i][j]) return false;
//		}
//	}
//	return true;
//}

void rec(int cnt, int idx) {
	if (siz == cnt) {
		che = true;
		return;
	}
	int row = blank[idx].first;
	int col = blank[idx].second;
	for (int k = 1; k < 10; k++) {
		if (c1[row][k] == 0 && c2[col][k] == 0 && c3[square(row, col)][k] == 0)
		{
			arr[row][col] = k;
			c1[row][k] = c2[col][k] = c3[square(row, col)][k] = true;
			rec(cnt + 1, idx + 1);
			if (che) return;
			c1[row][k] = c2[col][k] = c3[square(row, col)][k] = false;
			arr[row][col] = 0;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> arr[i][j]; // 스도쿠 채우기
			if (arr[i][j] == 0) {
				siz++;
				blank.push_back({ i,j });
			}
			else
			{
				c1[i][arr[i][j]] = c2[j][arr[i][j]] = true; // 열과 행의 가능한지 check
				c3[square(i, j)][arr[i][j]] = true;
			}
		}
	}
	rec(0, 0);
	cout << "\n";
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}
