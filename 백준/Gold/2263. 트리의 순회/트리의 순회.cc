#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

vector<int> in_Order;   // 중위 순회 같은경우
vector<int> post_Order; // 후위 순회의 경우 마지막 node 가 root 노드이다.
vector<pair<int, int>> tree;
unordered_map<int, int> in_order_idx;

int n;

int rec_tree(int in_start, int in_end, int post_start, int post_end)
{ // 시작 idx , 끝 idx post_Order 을 사용한 idx 임
  if (in_start > in_end || post_start > post_end)
    return 0;
  int root_node = post_Order[post_end];

  int root_node_idx = in_order_idx[root_node]; // root 노드의 in_oder_idx 값

  int left_sub_tree_size = root_node_idx - in_start;

  tree[root_node].first = rec_tree(in_start, root_node_idx - 1, post_start, post_start + left_sub_tree_size - 1);
  tree[root_node].second = rec_tree(root_node_idx + 1, in_end, post_start + left_sub_tree_size, post_end - 1);

  return root_node;
}
void pre_order(int node)
{
  if (node == 0)
    return;
  cout << node << " ";
  pre_order(tree[node].first);
  pre_order(tree[node].second);
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;

  tree = vector<pair<int, int>>(n + 1, {0, 0}); // tree vector 초기화
  for (int i = 0; i < n; i++)
  {
    int node;
    cin >> node;
    in_Order.push_back(node);
    in_order_idx[node] = i;
  }

  for (int i = 0; i < n; i++)
  {
    int node;
    cin >> node;
    post_Order.push_back(node);
  }
  int root_node = rec_tree(0, n - 1, 0, n - 1);
  pre_order(root_node);
  return 0;
}