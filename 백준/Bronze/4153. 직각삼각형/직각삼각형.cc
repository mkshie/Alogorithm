#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int arr[3];
	while (true) {
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
			break;
		}
		sort(arr, arr + 3);
		int a = pow(arr[0], 2), b = pow(arr[1], 2), c = pow(arr[2], 2);
		if (c ==  b + a) cout << "right\n";
		else cout << "wrong\n";
	}
}