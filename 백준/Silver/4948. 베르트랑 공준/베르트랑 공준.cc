#include <iostream>
#include <vector>

using namespace std;

//에라토스테네스의 체
vector<int> findprime(int limit) {
	vector<bool> primes(limit + 1, true);
	primes[0] = primes[1] = false;

	for (int i = 2; i * i <= limit; i++) {
		if (primes[i]) {
			for (int j = i * i; j <= limit; j += i) {
				//j 가 i * i 인 이유는 j 이전의 배수들은 그 이전의 소수들의 배수에서
				//지워졌기때문  2 일경우는 4부터 시작 3 일경우는 9부터 시작 5일경우는 25부터 시작
				// 5 10 15 20 여기서 10 15 20 은 이미 2 의 배수에서 3 의배수에서 지워졌다.
				primes[j] = false;
			}
		}
	}

	//primes 벡터에는 소수인것들만 true 로 남아있음.
	vector <int> result;
	for (int i = 2; i <= limit; i++) {
		if (primes[i]) {
			result.push_back(i);
		}
	}

	return result;
}

int main() {
	vector<int> primes = findprime(123456 * 2);
	int a;
	while (true) {
		cin >> a;
		int answer = 0;
		if (a == 0) break;
		else
		{
			
			for (int prime : primes) {
				if (prime > a && prime <= 2 * a) {
					answer++;
				}
				else if (prime > 2 * a) break;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}