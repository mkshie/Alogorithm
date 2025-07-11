#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int X;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> graph;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> X;
    // BFS 로 푸는게 맞는 거 같은데...흠...
    // DP로 풀어야한다고 함...
    pq.push({0, X});
    graph = vector<int>(X + 1, -1);
    int cnt, num;
    while (!pq.empty())
    {
        cnt = pq.top().first;
        num = pq.top().second;

        pq.pop();

        if (num == 1)
        {
            cout << cnt << "\n";
            break;
        }

        if (num % 3 == 0)
        {
            if (graph[num / 3] == -1)
            {
                pq.push({cnt + 1, num / 3});
                graph[num / 3] = num;
            }
        }
        if (num % 2 == 0)
        {
            if (graph[num / 2] == -1)
            {
                pq.push({cnt + 1, num / 2});
                graph[num / 2] = num;
            }
        }
        if(graph[num - 1] == -1){
            pq.push({cnt + 1, num - 1});
            graph[num - 1] = num;
        }
    }
    stack<int> path;
    cnt++;
    while (cnt--)
    {
        path.push(num);
        num = graph[num];
    }
    while(!path.empty()){
        int node = path.top();
        cout << node << " ";
        path.pop();
    }
    cout << "\n";
    return 0;
}