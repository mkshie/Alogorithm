#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

//처음 문제를 풀때 스택으로 푸는 방법이 생각이 나지 않아서 우선순위 큐를 통해 for 문 한번만에 문제를 풀었다.
//생각보다 오래걸리지만 최소힙을 사용하여 풀게된다면 나는 왼쪽부터 값을 확인하기 때문에 최소힙의 맨 윗부분값보다  지금 현재 보고있는 수가 더 작다면
//해당 수가 오큰수가 되고 이후 오큰수가 아닐때까지 Pop 을 해준뒤 다시 자신의 수를 현재 자신의 수를 push 해준다.

//stack 으로 푸는 방법은 매우 간단하다. stack 은 LIFO 방식이기 때문에
//뒤쪽부터 stack 에 값을 넣는다면... 나보다 값이 작은 애들이 없도록 pop() 을 해주게 되면 stack 이 비어있지 않은 이상
//stack 의 top 이 오큰수가 된다. 처음에 이 생각을 했다가 중간에 오큰수를 날릴 수도 있는거 아닌가 생각을 했었는데
//문제를 잘 못 이해해 다른 방식으로 문제를 풀어버렸다..

int answer[1000001] = {0};

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
    stack<int> st;
    memset(answer, -1, sizeof(answer));
    for (int i = N - 1; i >= 0; i--)
    {
        while(!st.empty() && st.top() <= arr[i]) // stack 의 제일 위의 값이 나보다 작다면
        {
            st.pop();
        }
        if(!st.empty()) // 스택이 비어있지 않다면 stack 의 제일 윗부분이 내 오큰수임
        {
            answer[i] = st.top();
        }
        st.push(arr[i]); // 내 값 역시 삽입해줘야함
    }
    for (int i = 0; i < N; i++)
    {
        cout << answer[i] << " ";
    }
    return 0;

    // pq.push({arr[0], 0});
    // for (int i = 1; i < N; i++)
    // {
    //     if(pq.top().first > arr[i]) //해당 값이 pq 에 있는 제일 작은값보다 값이 작다면
    //     {
    //         pq.push({arr[i], i});
    //         continue;
    //     }
    //     else{
    //         while(!pq.empty() && pq.top().first < arr[i]){
    //             int idx = pq.top().second;
    //             answer[idx] = arr[i];
    //             pq.pop();
    //         }
    //     }
    //     pq.push({arr[i], i});
    // }
    // while(!pq.empty()){
    //     int idx = pq.top().second;
    //     answer[idx] = -1;
    //     pq.pop();
    // }
    // for (int i = 0; i < N; i++)
    // {
    //     cout << answer[i] << " ";
    // }
    // return 0;
}