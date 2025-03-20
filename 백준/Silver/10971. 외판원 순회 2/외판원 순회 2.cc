#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> arr(10, vector<int>(10, 0));
vector<int> street;
vector<bool> visited(10, false); // true 방문 함
long long int sum = 0;
long long int answer = 999999999;
int N;

void add_point(){
    for (int i = 0; i < N - 1;i++){
        sum += arr[street[i]][street[i + 1]];
    }
    sum += arr[street.back()][street[0]];
    answer = min(sum, answer);
    sum = 0;
    return;
}

void rec(int size){
    if(size == N){
        if(arr[street.back()][street[0]] !=  0){
            add_point();
        }
        return;
    }
    for (int i = 0; i < N; i++){
        if(!visited[i] && ( size == 0 || arr[street.back()][i])){
            visited[i] = true;
            street.push_back(i);
            rec(size+1);
            visited[i] = false;
            street.pop_back();
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cin >> arr[i][j];
        }
    }
    rec(0);
    cout << answer << "\n";
}