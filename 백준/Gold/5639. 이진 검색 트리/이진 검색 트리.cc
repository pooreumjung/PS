#include<iostream>
using namespace std;
struct node {
	int data;
	node* left;
	node* right;
};
node* insert(node* root, int data) {
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->left = NULL;
		root->right = NULL;
	}
	else if (root->data < data)
		root->right = insert(root->right, data);
	else
		root->left = insert(root->left, data);
	return root;
}
void postorder(node *root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int input;
	node* root = NULL;
	while (cin >> input) {
		root = insert(root, input);
	}
	postorder(root);

}