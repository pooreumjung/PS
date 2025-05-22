#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;

int ans;
struct mergeSortTree {
	vector<vector<int>>v;
	void init(int node, int start, int end, vector<int>& u) {
		if (start == end) {
			v[node].push_back(u[start - 1]);
			return;
		}
		int mid = (start + end) / 2;
		init(node * 2, start, mid, u);
		init(node * 2 + 1, mid + 1, end, u);

		v[node].resize(v[node * 2].size() + v[node * 2 + 1].size());
		merge(v[node * 2].begin(), v[node * 2].end(), v[node * 2 + 1].begin(), v[node * 2 + 1].end(), v[node].begin());
	}
	
	int gt(int node, int start, int end, int l, int r, int x) {
		if (end<l || start>r)
			return 0;
		if (l <= start && end <= r)
			return v[node].end() - upper_bound(v[node].begin(), v[node].end(), x);
		int mid = (start + end) / 2;
		return gt(node * 2, start, mid, l, r, x) + gt(node * 2 + 1, mid + 1, end, l, r, x);
	}

};
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	mergeSortTree f;
	f.v.resize(1 << 18);
	int N, M;
	cin >> N;

	vector<int>v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	f.init(1, 1, N, v);

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
 		cin >> a >> b >> c;
		if(i==0)
			ans = f.gt(1, 1, N, a, b, c);
		else
		{
			a ^= ans;
			b ^= ans;
			c ^= ans;
			ans = f.gt(1, 1, N, a, b, c);

		}
		cout << ans << '\n';

	}
}