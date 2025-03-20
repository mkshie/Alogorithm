#include <iostream>
#include <algorithm>

using namespace std;
int N, S;
vector<int> arr;
//vector<bool> visited;
vector<int> permutation;

int answer = 0;
int sum = 0;

void rec(int size ,int cnt){
    if(size == permutation.size()){
        for(int i : permutation){
            sum += i;
        }
        if(sum == S)
            answer++;
        sum = 0;
        return;
    }

    for (int i = cnt; i < N;i++){
        permutation.push_back(arr[i]);
        rec(size, i + 1);
        permutation.pop_back();
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> S;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    for (int i = 1; i <= N;i++){
        rec(i, 0);
    }
    cout << answer << "\n";
}