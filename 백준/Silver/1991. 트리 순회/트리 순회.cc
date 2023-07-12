#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#define ull long long int
using namespace std;
struct Node
{
	int ID;
	Node* Left;
	Node* Right;
};
Node* arr[30];
void preorder(Node *n)
{
	cout << char(n->ID + 'A');
	if (n->Left != nullptr)
		preorder(n->Left);
	if (n->Right != nullptr)
		preorder(n->Right);
	return;
}
void inorder(Node* n)
{
	if (n->Left != nullptr)
		inorder(n->Left);
	cout << char(n->ID + 'A');
	if (n->Right != nullptr)
		inorder(n->Right);
	return;
}
void postorder(Node* n)
{
	if (n->Left != nullptr)
		postorder(n->Left);
	if (n->Right != nullptr)
		postorder(n->Right);
	cout << char(n->ID + 'A');
	return;
}
int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		Node* n = new Node();
		n->ID = i;
		arr[i] = n;
	}

	for (int i = 0; i < N; i++)
	{
		int ID, IDL, IDR;
		char N, L, R;
		cin >> N >> L >> R;
		ID = (int)N - 'A';
		IDL = (int)L - 'A';
		IDR = (int)R - 'A';
		if (IDL != -19)
			arr[ID]->Left = arr[IDL];
		if (IDR != -19)
			arr[ID]->Right = arr[IDR];
	}
	// 탐색 진행
	preorder(arr[0]);
	cout << '\n';
	inorder(arr[0]);
	cout << '\n';
	postorder(arr[0]);

	return 0;
}
