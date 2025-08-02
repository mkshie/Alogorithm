#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<char> arr;
    arr.resize(n, 'a');
    for (char ch : arr)
        cout << ch;
    return 0;
}