#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long>tree;
void setTree(int i);
long getMin(long s, long e);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int treeHeight = 0;
	int length = N;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = int(pow(2, treeHeight + 1));
	int leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);

	for (int i = leftNodeStartIndex + 1; i <= N + leftNodeStartIndex; i++)
		cin >> tree[i];

	setTree(treeSize - 1);
	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		long s = leftNodeStartIndex + start;
		long e = leftNodeStartIndex + end;
		cout << getMin(s, e) << '\n';
	}
}
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] = min(tree[i],tree[i-1]);
		i-=2;
	}
}
long getMin(long s, long e) {
	long nodeMin = 1000000001;
	while (s <= e) {
		if (s % 2 == 1) {
			nodeMin = min(nodeMin, tree[s]);
			s++;
		}
		if (e % 2 == 0) {
			nodeMin = min(nodeMin, tree[e]);
			e--;
		}
		s /= 2;
		e /= 2;
	}
	return nodeMin;
}