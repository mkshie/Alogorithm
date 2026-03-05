#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, K;

vector<long long> seg_tree;
vector<long long> arr;

long long build_seg(int idx, int l, int r)
{
    if (l == r)
    {
        seg_tree[idx] = arr[l];
    }
    else
    {
        long long sum_left = build_seg(idx * 2, l, (l + r) / 2);
        long long sum_right = build_seg(idx * 2 + 1, (l + r) / 2 + 1, r);

        seg_tree[idx] = sum_left + sum_right;
    }

    return seg_tree[idx];
}

void update_seg(int idx, int l, int r, long long chang_num, int node)
{
    // 해당 함수에서 해줘야하는건 최고 위 함수부터
    if (l <= node && r >= node)
    {
        // 두개 사이에 있다면
        seg_tree[idx] += chang_num;
        if (l == r)
            return;
        update_seg(idx * 2, l, (l + r) / 2, chang_num, node);
        update_seg(idx * 2 + 1, (l + r) / 2 + 1, r, chang_num, node);
    }
    return;
}

long long cal_seg(int idx, int l, int r, int st, int end)
{
    // st , end 가 찾는 구간 l r 이 원래 구간
    if (st <= l && r <= end)
    {
        return seg_tree[idx];
    }

    // 해당 부분이 제일 헷갈렸음 구간이 일부라도 겹치면 일단 내려가서 확인을해야하고 아예 범위 밖이라면 안하기때문에 아래와 같이 조건을 설정하는것
    if (end < l || r < st)
    {
        return 0;
    }

    int m = (l + r) / 2;
    return cal_seg(idx * 2, l, m, st, end) + cal_seg(idx * 2 + 1, m + 1, r, st, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 0; i < N; i++)
    {
        long long num;
        cin >> num;
        arr.push_back(num);
    }

    seg_tree.resize(4 * N);

    build_seg(1, 0, N - 1);

    for (int i = 0; i < M + K; i++)
    {
        int num;
        long long num2, num3;
        cin >> num >> num2 >> num3;

        if (num == 1)
        {
            long long chang_num = num3 - arr[num2 - 1];
            update_seg(1, 0, N - 1, chang_num, num2 - 1);
            arr[num2 - 1] = num3;
        }
        else if (num == 2)
        {
            cout << cal_seg(1, 0, N - 1, num2 - 1, num3 - 1) << "\n";
        }
    }
}