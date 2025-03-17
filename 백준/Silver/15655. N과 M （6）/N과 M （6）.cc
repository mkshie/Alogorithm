#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> arr;
vector<int> answer;
int N, M;

void rec(int cnt ,int size){
    if(size == M){
        for(int a : answer){
            cout << a << " ";
        }
        cout << "\n";
    }
    for (int i = cnt; i < N;i++){
        answer.push_back(arr[i]);
        rec(i + 1, size + 1);
        answer.pop_back();
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> N >> M;
    arr = vector<int>(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // 오름차순으로 정렬
    rec(0,0);
    return 0;
}