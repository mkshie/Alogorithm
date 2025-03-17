#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> answer;

void rec(int size){ // 배열의 크기를 나타냄
    if(size == M){
        for(int a : answer){
            cout << a << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N;i++){
        answer.push_back(arr[i]);
        rec(size + 1);
        answer.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    rec(0);
}