#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int> a , pair<int,int>b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int start, end;
        cin >> start >> end;
        arr.push_back({start, end});
    }
    sort(arr.begin(), arr.end(), cmp);
    int cnt = 0;
    int end_time = 0;
    for (int i = 0; i < N;i++){
        if(arr[i].first >= end_time){
            cnt++;
            end_time = arr[i].second;
        }
    }
    cout << cnt << "\n";
    return 0;
}

// 5
// 1 4 2 3 3 3 4 4 1 5