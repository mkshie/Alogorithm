#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <stack>

using namespace std;

char arr_ch[4] = {'D', 'S', 'L', 'R'};

int order(int num , char ch){
    if(ch == 'D'){
        num = (num * 2) % 10000;
    }
    else if (ch == 'S')
    {
        num = num - 1;
        if(num == -1)
            num = 9999;
    }
    else if (ch == 'L')
    {
        num = (num % 1000) * 10 + (num / 1000);
    }
    //1234 -> 4123
    else if (ch == 'R')
    {
        num = (num % 10) * 1000 + (num / 10);
    }

    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--){

        vector<int> visited(10000, -1);
        vector<pair<char,int>> prev(10000,{'0',-1}); //이전 명령어와 값
        queue<pair<int, int>> q;

        int A, B;
        cin >> A >> B;
        visited[A] = 0;
        q.push({0,A});
        int cnt, num;
        while (!q.empty())
        {
            cnt = q.front().first;
            num = q.front().second;

            q.pop();

            if(num == B)
            {
                break;
            }

            for (int i = 0; i < 4;i++){
                int next_num = order(num, arr_ch[i]);
                if(visited[next_num] == -1 || visited[next_num] > cnt+1){ // 처음 도착한 곳 이거나, 아니면 방문횟수가 더 적다면
                    q.push({cnt + 1, next_num});
                    visited[next_num] = cnt + 1;
                    prev[next_num] = {arr_ch[i], num}; // 경로 추적을 위한 배열
                }
            }
        }
        stack<char> st;
        for (int i = B; i != -1; i = prev[i].second){
            st.push(prev[i].first);
        }
        if(st.top() == '0')
            st.pop();
        while (!st.empty())
        {
            cout << st.top();
            st.pop();
        }
        cout << "\n";
    }
}