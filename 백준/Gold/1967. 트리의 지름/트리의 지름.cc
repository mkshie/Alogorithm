#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>> tree[10001];
int answer = 0;
int n;

int dfs(int start){
    vector<int> arr;
    for (int i = 0; i < tree[start].size(); i++)
    {
        arr.push_back(dfs(tree[start][i].first) + tree[start][i].second);
    }
    if(arr.size()>1){
        sort(arr.begin(), arr.end(), greater<int>());
        answer = max(arr[0] + arr[1], answer);
    }
    else if(arr.size()==0){
        return 0;
    }
    else{
        answer = max(arr[0], answer);
    }
    return arr[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n - 1;i++){
        int par, chi, weight;
        cin >> par >> chi >> weight;
        tree[par].push_back({chi, weight});
    }
    dfs(1);
    cout << answer << "\n";
}