#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;
vector<int> arr2;
vector<bool> visited;

void back_tracking(int depth){
    if(arr2.size() == M){
        for(int a : arr2){
            cout << arr[a] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i < N + 1;i++){
        if(!visited[i]){
            arr2.push_back(i);
            visited[i] = true;
            back_tracking(i);
            visited[i] = false;
            arr2.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    visited = vector<bool>(N + 1, false);
    arr = vector<int>(N + 1);
    for (int i = 1; i < N+1;i++){
        cin >> arr[i]; // string 배열 받는 곳
    }
    sort(arr.begin(), arr.end()); // vector string 사전 순 정렬
    back_tracking(0);
    return 0;
}