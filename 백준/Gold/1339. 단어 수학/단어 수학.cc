#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <tuple>

using namespace std;

bool cmp(int &a , int &b){
    return a > b;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int graph[26] = {0};
    for (int i = 0; i < N; i++)
    {
        string str1;
        cin >> str1;
        int pow = 1;
        for (int j = str1.size()-1; j >= 0; j--)
        {
            graph[str1[j] - 'A'] += pow;
            pow *= 10; // 가중치 더해주기 
        }
    }
    sort(graph, graph + 26, cmp);
    int number = 9;
    long long answer = 0;
    for (int i = 0; i < 26; i++)
    {
        if(graph[i] == 0) continue;
        answer += number * graph[i];
        number--;
    }
    cout << answer << "\n";
}