#include <iostream>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

int T , F;
map<string, string> parent;
map<string, int> tree_size;

string find(string str1){
    if(parent[str1] == str1)
        return str1;
    return parent[str1] = find(parent[str1]);
}

string merge(string str1, string str2){
    str1 = find(str1);
    str2 = find(str2);
    if(str1 == str2)
        return str1;
    parent[str1] = str2;
    tree_size[str2] += tree_size[str1];
    return str2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while(T--){
        cin >> F;
        for (int i = 0; i < F;i++){
            string str1, str2;
            cin >> str1 >> str2;
            if(!parent.count(str1)){ //map 에 존재하지 않는다면
                parent[str1] = str1;
                tree_size[str1] = 1;
            }
            if (!parent.count(str2))
            {
                parent[str2] = str2;
                tree_size[str2] = 1;
            }
            string tree_node = merge(str1, str2); // 서로 친구로 합쳐준 뒤
            cout << tree_size[tree_node] << "\n"; //트리 개수 출력하기
        }
        parent.clear();
        tree_size.clear();
    }
}