#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long>tree;
void setTree(int i);
long getSum(int start, int end);
void changeVal(int index, long value);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int length = N;
	int treeHeight = 0;

	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = int(pow(2, treeHeight + 1));
	int nodeLeftStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);

	for (int i = nodeLeftStartIndex+1; i <= N+nodeLeftStartIndex; i++)
		cin >> tree[i];
	setTree(treeSize - 1);

	for (int i = 0; i < M; i++) {
		long x, y, a, b;
		cin >> x >> y >> a >> b;
		if (x > y)
			swap(x, y);
		long start = x + nodeLeftStartIndex;
		long end = y + nodeLeftStartIndex;
		cout << getSum(start, end) << '\n';
		int index = a + nodeLeftStartIndex;
		changeVal(index, b);
	}
}
void setTree(int i) {
	while (i > 1) {
		tree[i / 2] += tree[i];
		i--;
	}
}
long getSum(int start, int end) {
	long sum = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			sum += tree[start];
			start++;
		}
		if (end % 2 == 0) {
			sum += tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return sum;
}
void changeVal(int index, long value) {
	long diff = value - tree[index];
	while (index > 0) {
		tree[index] += diff;
		index /= 2;
	}
}