#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<long>tree;
void changeVal(int index, long value);
long getMul(int start, int end);
void setTree(int i);
int main() {

	int N, M, K;
	cin >> N >> M >> K;



	int treeHeight = 0;
	int length = N;

	while (length != 0) {
		length /= 2;
		treeHeight++;
	}

	int treeSize = int(pow(2, treeHeight + 1));
	int nodeLeftStartIndex = treeSize / 2 - 1;
	tree.resize(treeSize + 1);

	fill(tree.begin(), tree.end(), 1);
	for (int i = nodeLeftStartIndex + 1; i <= nodeLeftStartIndex + N; i++)
		cin >> tree[i];
	setTree(treeSize - 1);
	for (int i = 0; i < M + K; i++) {
		long a, s, e;
		cin >> a >> s >> e;
		if (a == 1) {
			int start = s + nodeLeftStartIndex;
			changeVal(start, e);
		}
		else if (a == 2) {
			long start = s + nodeLeftStartIndex;
			long end = e + nodeLeftStartIndex;
			cout << getMul(start, end) << '\n';
		}
	}
}
void changeVal(int index, long value) {
	tree[index] = value;
	while (index > 1) {
		index /= 2;
		tree[index] = tree[index * 2] %1000000007 * tree[index * 2 + 1] % 1000000007;
	}

}
long getMul(int start, int end) {
	long mul = 1;
	while (start <= end) {
		if (start % 2 == 1) {
			mul = mul * tree[start] % 1000000007;
			start++;
		}
		if (end%2==0) {
			mul = mul * tree[end] % 1000000007;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return mul;
}
void setTree(int i) {
	while (i != 1) {
		tree[i / 2] = (tree[i] * tree[i / 2]) % 1000000007;
		i--;
	}

}