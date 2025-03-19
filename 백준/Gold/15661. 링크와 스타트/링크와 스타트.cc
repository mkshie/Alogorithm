#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> team_point;
vector<int> team_check; // 1 이 link 팀 0 이 start 팀
int answer = 9999999;
int link_point = 0;
int start_point = 0;

void back_tracking(int size , int cnt , int team_link_cnt){
    if(size == team_link_cnt) // link 팀의 크기를 만족했다면
    {
        link_point = 0;
        start_point = 0;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if(team_check[i] && team_check[j])
                {   
                    link_point += team_point[i][j];
                }
                else if(!team_check[i] && !team_check[j])
                {
                    start_point += team_point[i][j];
                }
            }
        }
        answer = min(answer, abs(link_point - start_point));
        return;
    }

    for (int i = cnt; i <= N; i++){
        team_check[i] = 1;
        back_tracking(size, i + 1, team_link_cnt + 1);
        team_check[i] = 0;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    team_point = vector<vector<int>>(N + 1, vector<int>(N + 1, 0));
    team_check = vector<int>(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N;j++){
            cin >> team_point[i][j];
        }
    }
    for (int i = 1; i < (N/2)+1; i++){
        back_tracking(i, 1 , 0);
    }
    cout << answer << "\n";
    return 0;
}