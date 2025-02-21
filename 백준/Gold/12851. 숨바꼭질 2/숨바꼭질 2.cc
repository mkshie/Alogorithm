#include <iostream>
#include <algorithm>
#include <stack>
#include <deque>
#include <queue>

using namespace std;

//코드를 수정하다보니 문제가 많이 생겼음
//굳이 queue 에 위치와 걸린 시간까지 같이 넣으려고 하니 오히려 데이터가 쌓이는 현상이 발생
//그래서 방문여부를 체크해주는 변수를 int 형으로 바꿔서 해당칸에서 최소인지 또는 처음 도착했는지를 파악해주게끔 수정했더니
//코드가 더욱 간결해짐 기억해두자

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K; // N 은 수빈 K 는 동생
    cin >> N >> K;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> arr;
    vector<int> che_visit(100010, 0); // 0일경우 처음 도착 , 0이 아닐경우에는 이미 와본적이 있는경우니 pass 하지만
                                      // 이전 경우의 수와 횟수가 똑같다면 다른 경로로 최단시간내에 온것이니 queue 에 예외적으로 삽입해주자
    int cnt, cur_location;
    arr.push({0, N});
    int count_num = 0; // 목적지에 최단거리로 도착한 경우의 수
    int three[3] = {1, -1, 2};
    che_visit[N] = 1;
    while (!arr.empty())
    {
        cnt = arr.top().first;
        cur_location = arr.top().second;
        arr.pop();
        if (cur_location == K)
        {
            count_num++;
            continue;
        }
        for (int i = 0; i < 3;i++){
            int fut_location;
            if (i == 2)
                fut_location = cur_location * three[i];
            else
                fut_location = cur_location + three[i];
            if(0<= fut_location && fut_location <=100000){

                if (che_visit[fut_location] == 0)
                { // 첫 방문 시
                    che_visit[fut_location] = che_visit[cur_location] + 1;
                    arr.push({cnt + 1, fut_location});
                }
                else if(che_visit[fut_location] == (che_visit[cur_location]+1)){
                    arr.push({cnt + 1, fut_location});
                }
            }
        }
    }
    cout << che_visit[K] - 1 << "\n";
    cout << count_num << "\n";
    return 0;
}
