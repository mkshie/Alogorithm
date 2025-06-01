#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int tree[1000001][2] = {0};

void rotation(int start){
    if(tree[start][0]!=0)
        rotation(tree[start][0]);
    if(tree[start][1]!=0)
        rotation(tree[start][1]);
    cout << start << "\n";
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int par_node;
    cin >> par_node;
    int root = par_node;
    int next_node;
    stack<int> par_nodes;
    while (cin >> next_node)
    {
        if(next_node < par_node){
            par_nodes.push(par_node);
            tree[par_node][0] = next_node;
        }
        else{
            while(!par_nodes.empty() && par_nodes.top() < next_node){
                par_node = par_nodes.top();
                par_nodes.pop();
            }
                tree[par_node][1] = next_node;
        }
        par_node = next_node;
    }

    rotation(root);

    return 0;
}