#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int answer[1000000] = {0};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    priority_queue<pair<int, int>,vector<pair<int,int>> ,greater<pair<int,int>>> pq;
    vector<int> arr;
    for (int i = 0; i < N;i++){
        int num;
        cin >> num;
        arr.push_back(num);
    }
    pq.push({arr[0], 0});
    for (int i = 1; i < N; i++)
    {
        if(pq.top().first > arr[i]) //해당 값이 pq 에 있는 제일 작은값보다 값이 작다면
        {
            pq.push({arr[i], i});
            continue;
        }
        else{
            while(!pq.empty() && pq.top().first < arr[i]){
                int idx = pq.top().second;
                answer[idx] = arr[i];
                pq.pop();
            }
        }
        pq.push({arr[i], i});
    }
    while(!pq.empty()){
        int idx = pq.top().second;
        answer[idx] = -1;
        pq.pop();
    }
    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }
    return 0;
}