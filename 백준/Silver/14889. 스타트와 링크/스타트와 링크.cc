//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int status[20][20];
//int N;
//vector<bool> che;
//int result = 99999999;
//
////후...
//
//int score_rec() {
//	int sum = 0;
//	int sum2 = 0;
//	for (int i = 0; i < N; i++) {
//		for (int j = i + 1; j < N; j++) {
//			if (che[i] && che[j]) {
//				sum += status[i][j] + status[j][i];
//			}
//			else if (!che[i] && !che[j])
//			{
//				sum2 += status[i][j] + status[j][i];
//			}
//		}
//	}
//	return abs(sum - sum2);
//}
//
//void rec(int cnt , int idx) {
//	//if (result == 0) return;
//	if (cnt == N / 2) {
//		result = min(result, score_rec());
//		return;
//	}
//	for (int i = idx; i < N; i++) {
//		if (!che[i]) {
//			che[i] = true;
//			rec(cnt+1,i+1);
//			che[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
//	cin >> N;
//	che.resize(N, false);
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> status[i][j];
//		}
//	}
//	//che[0] = true;
//	rec(0,0);
//	cout << result;
//	return 0;
//
//}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int status[21][21];
int N;
vector<int> start;
vector<int> link;
vector<bool> che;
int result = 99999999;

int score_rec() {
	int sum = 0;
	for (int i = 0; i < N / 2; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			if (i != j) {
				sum += status[start[i]][start[j]] - status[link[i]][link[j]];
				sum += status[start[j]][start[i]] - status[link[j]][link[i]];
			}
		}
	}
	return sum;

}

void rec(int cnt, int idx) {
	if (cnt == N / 2) {
		int count = 0;
		for (bool k : che) {
			if (!k) link.push_back(count);
			count++;
		}
		int status_sum1 = abs(score_rec());
		if (result > status_sum1) result = status_sum1;
		link.clear();
		return;
	}
	for (int i = idx; i < N; i++) {
		if (!che[i]) {
			che[i] = true;
			start.push_back(i);
			rec(cnt + 1, i + 1);
			start.pop_back();
			che[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	che.resize(N, false);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}
	start.push_back(0);
	che[0] = true;
	rec(1, 1);
	cout << result;
	return 0;

}