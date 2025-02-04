#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;
int N, M;
vector <int> arr;


void rec_che(vector <bool> &che) {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i < N + 1; i++) {
		if (!che[i]) {
			arr.push_back(i);
			che[i] = true;
			rec_che(che);
			arr.pop_back();
			che[i] = false;
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M; 

	vector <bool> che(N + 1, false);
	rec_che(che);

}