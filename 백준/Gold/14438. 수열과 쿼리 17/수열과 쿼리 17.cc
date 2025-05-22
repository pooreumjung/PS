#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 1000000001
vector<int>tree,arr;
int initTree(int start, int end, int node);
int updateTree(int start, int end, int node, int index);
int findMin(int start, int end, int node, int left, int right);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,M,Q,index,value,left,right;
	cin >> N;
	arr.resize(N);
	tree.resize(N * 4);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	initTree(0, N - 1, 1);
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> Q;
		if (Q == 1) {
			cin >> index >> value;
			arr[index - 1] = value;
			updateTree(0, N - 1, 1,index - 1);
		}
		else {
			cin >> left >> right;
			cout << findMin(0, N - 1, 1, left - 1, right - 1) << '\n';
		}
	}


}
int initTree(int start, int end, int node) {
	if (start == end)
		return tree[node] = arr[start];
	int mid = (start + end) / 2;
	int leftmin = initTree(start, mid, node * 2);
	int rightmin = initTree(mid + 1, end, node * 2 + 1);
	if (leftmin < rightmin)
		return tree[node] = leftmin;
	else
		return tree[node] = rightmin;
}
int updateTree(int start, int end, int node, int index) {
	if (index<start || index>end)
		return tree[node];
	if (start == end)
		return tree[node] = arr[index];
	int mid = (start + end) / 2;
	int leftmin = updateTree(start, mid, node * 2, index);
	int rightmin = updateTree(mid + 1, end, node * 2 + 1, index);
	return tree[node] = min(leftmin, rightmin);
}
int findMin(int start, int end, int node, int left, int right) {
	if (left > end || right < start)
		return INF;
	if (left <= start && right >= end)
		return tree[node];
	int mid = (start + end) / 2;
	int leftmin = findMin(start, mid, node * 2, left, right);
	int rightmin = findMin(mid + 1, end, node * 2 + 1, left, right);
	return min(leftmin, rightmin);

}