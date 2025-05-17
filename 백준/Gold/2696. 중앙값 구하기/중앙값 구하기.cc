#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, M;
    cin >> T;
    while(T--){
        priority_queue<int> max_heap; // 최대값이 위로
        priority_queue<int, vector<int>, greater<int>> min_heap; // 최소값이 위로
        cin >> M;
        cout << (M % 2 == 1 ? M / 2 + 1 : M / 2) << "\n";
        for (int i = 0; i < M;i++){
            int num;
            cin >> num;
            if(i==0){
                cout << num << " "; // 처음으로 입력된 수는 무조건 입력
                max_heap.push(num);
                continue;
            }
            if(num < max_heap.top()){ // 값이 작다면
                max_heap.push(num);
            }
            else
                min_heap.push(num);
            
            if(max_heap.size() > min_heap.size() + 1){ //
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
            else if(min_heap.size() > max_heap.size() + 1){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
            if(i % 2 == 0)
                cout << (max_heap.size() > min_heap.size() ? max_heap.top() : min_heap.top()) << " ";
        }
        cout << "\n";
    }
}