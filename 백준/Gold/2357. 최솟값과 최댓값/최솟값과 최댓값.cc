#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 정수의 개수
int M; // 문제 횟수

// 일반적인 방식으로는 풀기힘듦
// 세그먼트 트리를 이용한 방식을 사용해야함

vector<int> arr;
vector<pair<int, int>> seg_tree;

pair<int, int> build(int idx, int left, int right)
{

    if (right >= N)
        return make_pair(-1, -1);

    if (left == right)
    {
        seg_tree[idx] = {arr[left], arr[left]};
        return make_pair(arr[left], arr[right]);
    }
    else
    {
        pair<int, int> left_result = build(idx * 2, left, (left + right) / 2);
        pair<int, int> right_result = build(idx * 2 + 1, (left + right) / 2 + 1, right);

        seg_tree[idx] = {min(left_result.first, right_result.first), max(left_result.second, right_result.second)};
        return seg_tree[idx];
    }
}

pair<int, int> cal(int l, int r, int node, int st, int end)
{
    // st   : 시작 인덱스
    // end  : 끝 인덱스
    // l~r  : 구하고자 하는 구간 합의 범위

    // 구간에 완전히 포함되는경우
    if (l <= st && end <= r)
        return seg_tree[node];

    if (r < st || end < l)
        return make_pair(1000000001, -1);

    int m = (st + end) / 2;

    pair<int, int> left_result = cal(l, r, node * 2, st, m);
    pair<int, int> right_result = cal(l, r, node * 2 + 1, m + 1, end);

    return make_pair(min(left_result.first, right_result.first), max(left_result.second, right_result.second));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    seg_tree.resize(N * 4);
    build(1, 0, N - 1);

    while (M--)
    {
        int num1, num2;
        cin >> num1 >> num2;

        pair<int, int> answer = cal(num1 - 1, num2 - 1, 1, 0, N - 1);

        cout << answer.first << " " << answer.second << "\n";
    }

    return 0;
}