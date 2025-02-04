#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;
int N, M;
vector <int> arr;



void rec_che(vector <bool>& che,int cnt) {
	if (arr.size() == M) {
		for (int num : arr) {
			cout << num << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = cnt; i < N + 1; i++) {
		if (!che[i]) {
			arr.push_back(i);
			che[i] = true;
			rec_che(che,i+1);
			che[i] = false;
			arr.pop_back();
		}
	}

}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector <bool> che(N + 1, false);
	rec_che(che,1);

}