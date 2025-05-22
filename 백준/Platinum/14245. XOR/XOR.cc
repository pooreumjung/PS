#include<iostream>
#include<vector>
using namespace std;
int N, M;
vector<long>arr, tree, lazy;
long initTree(int node, int start, int end);
long query(int node, int start, int end, int index);
long updateTree(int node, int start, int end, int l, int r, int value);
void lazyUpdate(int node, int start, int end);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	arr.resize(N+1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	tree.resize(4 * N);
	lazy.resize(4 * N);
	initTree(1, 0, N-1 );
	cin >> M;

	int index, l, r, value;
	while (M--) {
		int Q;
		cin >> Q;
		if (Q == 1) {
			cin >> l >> r >> value;
			updateTree(1, 0, N - 1, l, r, value);
		}
		else if (Q == 2) {
			cin >> index;
			cout << query(1, 0, N - 1, index)<<"\n";
		}
	}
}

long initTree(int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];

	long mid = (start + end) / 2;
	long left = initTree(node * 2, start, mid);
	long right = initTree(node * 2 + 1, mid + 1, end);

	return tree[node] = left ^ right;	
}

long query(int node, int start, int end, int index)
{
	lazyUpdate(node, start, end);

	if (start == end)
		return tree[node];

	int mid = (start + end) / 2;

	if (index <= mid)
		return query(node * 2, start, mid, index);
	else
		return query(node * 2 + 1, mid + 1, end, index);
	
}

long updateTree(int node, int start, int end, int l, int r, int value)
{
	lazyUpdate(node, start, end);

	if (r < start || end < l)
		return tree[node];

	if (l <= start && end <= r) {
		lazy[node] = value;
		lazyUpdate(node, start, end);
		return tree[node];
	}

	int mid = (start + end) / 2;
	long left = updateTree(node * 2, start, mid, l, r, value);
	long right = updateTree(node * 2+1, mid+1, end, l, r, value);
	
	return tree[node] = left ^ right;
}

void lazyUpdate(int node, int start, int end)
{
	if (lazy[node] == 0)
		return;
	
	if ((end - start + 1) % 2 == 1)
		tree[node] ^= lazy[node];

	if (start != end) {
		lazy[node * 2] ^= lazy[node];
		lazy[node * 2+1] ^= lazy[node];
	}

	lazy[node] = 0;

}
