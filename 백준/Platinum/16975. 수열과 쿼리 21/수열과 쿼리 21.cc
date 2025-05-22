#include<iostream>
#include<vector>
using namespace std;

#define ll long long
vector<ll>arr, tree, lazy;
ll initTree(ll node, ll start, ll end);
ll update(ll node, ll start, ll end, ll l, ll r, ll diff);
void lazyUpdate(ll node, ll start, ll end);
ll findValue(ll node, ll start, ll end, ll index);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N;

	arr.resize(N + 1);
	tree.resize(N * 4);
	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	initTree(1, 1, N);
	lazy.resize(N * 4);

	cin >> M;
	int query;
	while (M--) {
		cin >> query;
		if (query == 1) {
			ll l, r, value;
			cin >> l >> r >> value;
			update(1, 1, N, l, r, value);
		}
		else if (query == 2) {
			ll index;
			cin >> index;
			cout << findValue(1, 1, N, index) << '\n';
		}
	}
}

ll initTree(ll node, ll start, ll end)
{
	if (start == end)
		return tree[node] = arr[start];

	ll mid = (start + end) / 2;

	ll leftSum = initTree(node * 2, start, mid);
	ll rightSum = initTree(node * 2 + 1, mid + 1, end);

	return tree[node] = leftSum + rightSum;
}

ll update(ll node, ll start, ll end, ll l, ll r, ll diff)
{
	lazyUpdate(node, start, end);

	if (r < start || end < l)
		return tree[node];

	if (l <= start && end <= r) {
		lazy[node] += diff;
		lazyUpdate(node, start, end);
		return tree[node];
	}

	ll mid = (start + end) / 2;
	ll leftSum = update(node * 2, start, mid, l, r, diff);
	ll rightSum = update(node * 2 + 1, mid + 1, end, l, r, diff);

	return tree[node] = leftSum + rightSum;
}

void lazyUpdate(ll node, ll start, ll end)
{
	if (lazy[node] == 0)
		return;

	tree[node] += (end - start + 1) * lazy[node];

	if (start != end) {
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}

	lazy[node] = 0;
}

ll findValue(ll node, ll start, ll end, ll index)
{
	lazyUpdate(node, start, end);

	if (start == end)
		return tree[node];

	ll mid = (start + end) / 2;
	if (index <= mid)
		return findValue(node * 2, start, mid, index);
	else
		return  findValue(node * 2 + 1, mid + 1, end, index);
}
