#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>

using namespace std;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	set <string> mapping;

	string str1;
	cin >> str1;
	int x = str1.length();
	int answer = 0;
	for (int i = 0; i < x; i++) { //i 는 지금 찾는 단어의 길이
		for (int j = 0; j < x-i; j++) { //j 는 현재 시작점
			string str2 = str1.substr(j, i+1);
			mapping.insert(str2);

		}
	}

	cout<< mapping.size() << "\n";
	return 0;
}