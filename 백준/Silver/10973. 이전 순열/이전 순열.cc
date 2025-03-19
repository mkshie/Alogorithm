#include <iostream>
#include <algorithm>
#include <vector>


//next_permutaion , prev_permutation 사용 문제

using namespace std;

int N;
vector<int> arr;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    if(prev_permutation(arr.begin(),arr.end())){
        for(int i : arr)
            cout << i << " ";
        cout << "\n";
    }
    else
        cout << -1 << "\n";
    return 0;
}