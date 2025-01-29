#include <iostream>
#include <queue>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(string a, string b) {
	return (a.length() < b.length());
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	map <string, int> che;
	vector<string> word;
	int N;
	cin >> N;
	while (N--)
	{
		int i = 0;
		string word1;
		cin >> word1;
		if (che.find(word1) == che.end())
		{
			che.insert({ word1, i });
			word.push_back(word1);
			i++;
		}
	}
	sort(word.begin(), word.end());
	stable_sort(word.begin(), word.end(),cmp);

	for (auto a : word) cout << a << "\n";

}