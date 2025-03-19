#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int answer = 0;
    do
    {
        int sum = 0;
        for (int i = 0; i < N - 1; i++)
        {
            sum += abs(arr[i] - arr[i + 1]);
        }
        answer = max(sum, answer);
    } while (next_permutation(arr.begin(), arr.end()));
    cout << answer << "\n";
    return 0;
}