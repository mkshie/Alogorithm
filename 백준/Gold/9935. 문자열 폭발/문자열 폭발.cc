#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str1, bomb;
	cin >> str1 >> bomb;
	int bomblen = (int)bomb.size();
	bool flag = true;
	vector <char> str2;
	for (size_t i = 0; i < str1.size(); i++) { //i 는 str1 가르키는 idx 값
		str2.push_back(str1[i]);
		if (str2.size() >= bomblen) {  // str2 의 길이가 더 길다면 폭탄 문자열 확인해보기
			if (str2[str2.size() - 1] == bomb[bomblen - 1]) { // 맨 마지막 문자열 확인하기
				flag = false;
				for (size_t k = 1; k < bomblen; k++) {
					if (str2[str2.size() - 1 - k] != bomb[bomblen - 1 - k]) { // 그 다음 문자 확인해보기
						flag = true; // 만약 폭탄문자열과 다르다면 그냥 빠져나가기
						k = bomblen;
					}
				}
				if (flag == false) {
					for (size_t p = 0; p < bomblen; p++) { // 만약 flag 가 계속 false 라면 문자열 빼주기
						str2.pop_back();
					}
				}
			}
		}
		flag = true; // 확인후 다시 검증을 위해서 
	}
	if (str2.size() == 0)
		cout << "FRULA";
	else {
		for (size_t i = 0; i < str2.size(); i++) {
			cout << str2[i];
		}
	}
	return 0;
}