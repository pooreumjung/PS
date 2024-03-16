#include<iostream>
#include<vector>
#include<limits.h>
#include<cmath>
using namespace std;

vector<long>tree;
long getSum(int start, int end);
void changeVal(int index, long val);
void setTree(int i);

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, K;
	cin >> N >> M >> K;
	int treeHeight = 0;
	int length = N;

	while (length != 0) { // 트리의 높이 구하기
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int leftNodeStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);

	for (int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++)
		cin >> tree[i];
	setTree(treeSize - 1);

	for (int i = 0; i < M+K; i++) {
		long a, s, e;
		cin >> a >> s >> e;

		if (a == 1)
			changeVal(leftNodeStartIndex + s, e);
		else if (a == 2) {
			long start = leftNodeStartIndex + s;
			long end = leftNodeStartIndex + e;
			cout << getSum(start, end) << '\n';
		}
	}

}
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] += tree[i];
		i--;
	}

}
void changeVal(int index, long val) {
	long diff = val - tree[index];

	while (index > 0) {
		tree[index] = tree[index] + diff;
		index /= 2;
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