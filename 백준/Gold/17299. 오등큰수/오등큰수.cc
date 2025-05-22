#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int arr[1000001] = {0};
int arr_2[1000000] = {0};
vector<int> answer(1000000, -1);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr[num] += 1; // 몇번 나왔는지 체크하는 배열
        arr_2[i] = num; // 순차적으로 값을 저장
    }
    stack<int> st;
    for (int i = N - 1; i >= 0;i--){
        while(!st.empty() && arr[st.top()] <= arr[arr_2[i]]){ //stack 이 비어있지 않거나 해당 stack 의 제일 윗부분(가장 최근의 오른쪽의 F값이
        // 현재 F 값보다 작다면 stack 에서 빼줘야한다.)
        st.pop();
        }
        if(!st.empty() && arr[st.top()] > arr[arr_2[i]]){
            answer[i] = st.top();
        }
        st.push(arr_2[i]);
    }

    for (int i = 0; i < N;i++){
        cout << answer[i] << " ";
    }
    return 0;
}