#include <iostream>
using namespace std;

int main() {
	int b[42] = {0};
	int a[10] = {};
	int sum = 0;
	for (int i = 0; i < 10;i++)
	{
		cin >> a[i];
		a[i] = a[i] % 42;
		b[a[i]] += 1;
	}

	for (int k = 0; k < 42; k++) {

		if (b[k] != 0) { sum += 1; }

	}
	cout << sum << endl;
	return 0;
}