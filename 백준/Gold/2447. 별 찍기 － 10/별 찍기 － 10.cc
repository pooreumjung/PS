#include<iostream>
using namespace std;
int N;
char **arr;
void print_star(int y,int x,int len)
{
	if (len == 1)
	{
		arr[y][x] = '*';
		return;
	}
	int nx = len / 3;
	print_star(y, x, nx);
	print_star(y, x + nx, nx);
	print_star(y, x + nx * 2, nx);

	print_star(y + nx, x, nx);
	for (int i = y+nx; i < y + nx * 2; i++)
		for (int j = x+nx; j < x + nx * 2; j++) arr[i][j] = ' ';
	print_star(y + nx, x + nx * 2, nx);

	print_star(y + nx * 2,x, nx);
	print_star(y + nx * 2, x + nx, nx);
	print_star(y + nx * 2, x + nx * 2, nx);
}
int main()
{
	cin >> N;
	arr = new char*[N];
	for (int i = 0; i < N; i++) arr[i] = new char[N];
	print_star(0,0,N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++) cout << arr[i][j];
		cout << '\n';
	}
}
