#include<iostream>
#include<vector>
#define int long long
using namespace std;

vector<int> arr, tree, lazy; 

int init(int node, int start, int end) {
    if (start == end) 
        return tree[node] = arr[start];

    int leftSum = init(node * 2, start, (start + end) / 2);
    int rightSum = init(node * 2 + 1, (start + end) / 2 + 1, end);

    return tree[node] = leftSum + rightSum;
}

void lazyUpdate(int node, int start, int end) {
    if (lazy[node] == 0) 
        return;

    tree[node] += (end - start + 1) * lazy[node];

    if (start != end) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }

    lazy[node] = 0;
}

int updateTree(int node, int start, int  end, int l, int r, int diff) {
    lazyUpdate(node, start, end);

    if (r < start || end < l) return tree[node];

    if (l <= start && end <= r) {
        lazy[node] += diff;
        lazyUpdate(node, start, end);
        return tree[node];
    }

    int leftTree = updateTree(node * 2, start, (start + end) / 2, l, r, diff);
    int rightTree = updateTree(node * 2 + 1, (start + end) / 2 + 1, end, l, r, diff);

    return tree[node] = leftTree + rightTree;
}

int findSum(int node, int start, int end, int l, int r) {
    lazyUpdate(node, start, end);

    if (r < start || end < l) 
        return 0;
    if (l <= start && end <= r) 
        return tree[node];

    int leftTree = findSum(node * 2, start, (start + end) / 2, l, r);
    int rightTree = findSum(node * 2 + 1, (start + end) / 2 + 1, end, l, r);

    return leftTree + rightTree;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int N, M, K; 
    cin >> N >> M >> K;

    arr.resize(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    tree.resize(N * 4);
    init(1, 1, N);

    lazy.resize(N * 4);

    M += K;
    while (M--) {
        int query; 
        cin >> query;

        if (query == 1) {
            int a, b, c; 
            cin >> a >> b >> c;
            updateTree(1, 1, N, a, b, c);
        }
        else if (query == 2) {
            int a, b; 
            cin >> a >> b;
            cout << findSum(1, 1, N, a, b) << "\n";
        }
    }
}