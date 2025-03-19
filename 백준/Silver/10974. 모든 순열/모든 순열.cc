#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//next_permutaion , prev_permutaion 기억해두자

int main(){
    int N;
    cin >> N;
    vector<int> arr;
    for (int i = 1; i <= N;i++){
        arr.push_back(i);
    }
    do{
        for(int i : arr)
            cout << i << " ";
        cout << "\n";
    } while (next_permutation(arr.begin(), arr.end()));

    return 0;
}