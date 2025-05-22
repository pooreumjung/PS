#include<iostream>
using namespace std;

int tree[26][2];
int N;
void postorder(int root);
void inorder(int root);
void preorder(int root);
int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		char first, left, right;
		cin >> first >> left >> right;
		int node = first - 'A';
		if (left == '.')
			tree[node][0] = -1;
		else
			tree[node][0] = left - 'A';
		if (right == '.')
			tree[node][1] = -1;
		else
			tree[node][1] = right - 'A';
		
	}
	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';
}
void preorder(int root) {
	if (root == -1)
		return;

	cout << (char)(root + 'A');
	preorder(tree[root][0]);
	preorder(tree[root][1]);
}
void inorder(int root) {
	if (root == -1)
		return;
	inorder(tree[root][0]);
	cout << (char)(root + 'A');	
	inorder(tree[root][1]);
}
void postorder(int root) {
	if (root == -1)
		return;

	postorder(tree[root][0]);
	postorder(tree[root][1]);
	cout << (char)(root + 'A');

}