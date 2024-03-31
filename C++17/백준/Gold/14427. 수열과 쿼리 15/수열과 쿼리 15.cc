#include<iostream>
#include<vector>
using namespace std;

vector<int>tree, arr;
int initTree(int start, int end, int node);
int updateTree(int start, int end, int index,int value);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, Q, index, value;
	cin >> N;
	tree.resize(N*4);
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	initTree(0, N - 1, 1);
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> Q;
		if (Q == 1) {
			cin >> index >> value;
			arr[index - 1] = value;
			updateTree(0, N - 1, 1,index-1 );
		}
		else {
			cout << tree[1]+1 << "\n";
		}
	}

}
int initTree(int start, int end, int node) {
	if (start == end)
		return tree[node] = start;
	int mid = (start + end) / 2;
	int left = initTree(start, mid, node * 2);
	int right = initTree(mid + 1, end, node * 2 + 1);
	if (arr[left] > arr[right])
		return tree[node] = right;
	else if (arr[left] < arr[right])
		return tree[node] = left;
	else
		return tree[node] = min(left, right);
}
int updateTree(int start, int end, int node, int index) {
	if (index<start || index>end||start==end)
		return tree[node];
	int mid = (start + end) / 2;
	int left = updateTree(start, mid, node * 2, index);
	int right = updateTree(mid + 1, end, node * 2 + 1, index);
	if (arr[left] < arr[right])
		return tree[node] = left;
	else if (arr[right] < arr[left])
		return tree[node] = right;
	else
		return tree[node] = min(left, right);
}
