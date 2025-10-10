#include <string>
#include <vector>
#include <algorithm>
#include <iostream>



using namespace std;


vector<int> inDegree(1000001 , 0);
vector<int> outDegree(1000001, 0);
vector<vector<int>> graph (1000001);
vector<int> answer(4,0);
bool che = false;

 //생성된 정점으로 부터  dfs 를 시작하는데 돌아서 처음 정점으로 돌아오면 도넛 , 돌았는데 나가는 정점이 없다면 막대 , 나가는 간선이 두개 이상인 정점을 만나면 8자 이다.
void cheGraph(int startNode , int curNode){

    int nxtNode;
    
    for(int i = 0; i < graph[curNode].size(); i++){
        if(che)
            break;
        nxtNode = graph[curNode][i];
        
        //cout << startNode << " " << nxtNode << "test\n";
        //나가는 정점이 두개 이상인 Node 라면 끝
        if(outDegree[nxtNode] >= 2){
            answer[3]++;
            che = true;
            return;
        }
        
        if(startNode == nxtNode){
            //startNode 와 nxtNode 가 같은 경우는 도넛임 위의 조건문에 걸린적이 없으면 도넛의 경우만 남음
            answer[1]++;
            che = true;
            return;
        }
        
        if(graph[nxtNode].size() == 0){
            answer[2]++;
            che = true;
            return;
    }
        cheGraph(startNode , nxtNode);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    //먼저 생성한 정점 부터 찾기
    //생성된 정점은 들어오는 간선의 개수는 없지만 나가는 간선의 개수는 2개 이상인 정점
    //도넛의 경우 모든 노드는 나가고 들어가는 정점의 개수가 1개
    //막대으 경우 0 or 1 
    //8자의 경우 들어가고 나가는 노드가 2인 노드가 있다면 해당 노드는 8자

    int max_num = 0;
    
    for(vector<int> arr : edges){
        outDegree[arr[0]]++;
        inDegree[arr[1]]++;
        max_num = max(max_num , max(arr[0] , arr[1]));
    }
    
    // vector<vector<int>> graph (max_num + 1);
    int createdNode;
    
    for(int i = 1 ; i <= max_num ; i++){
        if(inDegree[i] == 0 && outDegree[i] >= 2){
            createdNode = i;
            answer[0] = i;
        }
    }
    //cout << createdNode <<"\n";
    vector<int> startNode;
    for(vector<int> arr : edges){
        if(arr[0] != createdNode)
            graph[arr[0]].push_back(arr[1]);
        else
            startNode.push_back(arr[1]);
    }
    int start , cur , nxt;
    for(int i = 0; i < startNode.size(); i++){
        start = startNode[i];
        cur = startNode[i];
        if(graph[cur].size() == 0){ // nxt node 가 존재하지 않다면 바로 막대 그래프
            answer[2]++;
            continue;
        }
        //cout << start << " " << cur;
        //cout << graph[cur].size();
        cheGraph(start,cur);
        che = false;
    }
    
    //생성된 정점으로 부터  dfs 를 시작하는데 돌아서 처음 정점으로 돌아오면 도넛 , 돌았는데 나가는 정점이 없다면 막대 , 나가는 간선이 두개 이상인 정점을 만나면 8자 이다.

    return answer;
}