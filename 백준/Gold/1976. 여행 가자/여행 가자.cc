#include <iostream>
#include <vector>

using namespace std;

//먼저 이어진 애들끼리는 union 함수를 통해 합치기.
//이후 되는지 판별 여부는 이전 집과 동일하다면 yes 아니라면 no 로 하면 될듯

vector<int> parent;

int find(int u){
    if(parent[u] == u)
        return u;
    return parent[u] = find(parent[u]); // 아니라면 재귀적으로 부모 노드를 업데이트 하기
    //시간 단축에 매우 좋음.
}

void merge(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v)
        return;
    parent[u] = v;
}

int main(){

    int N , M;
    cin >> N >> M;
    parent = vector<int>(N + 1, 0);
    for (int i = 0; i <= N;i++){
        parent[i] = i; // 부모노드를 자기 자신으로 초기화하기
    }
    for (int i = 1; i <= N;i++){
        for (int j = 1; j <= N;j++){
            int num;
            cin >> num;
            if(num == 1){
                merge(i, j);
            }
        }
    }
    int st_node, ne_node;
    cin >> st_node;
    for (int i = 1; i < M;i++){
        cin >> ne_node;
        if(find(st_node) != find(ne_node)){
            cout << "NO\n";
            return 0;
        }
        st_node = ne_node;
    }
    cout << "YES\n";
    return 0;
}