#include<iostream>
using namespace std;
int arr[100][100];
void floyd(int n) {
	//x는 거쳐가는, y는 출발, z는 도착
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			for (int z = 0; z < n; z++) {
				if (arr[y][x]+ arr[x][z] >= 2)
					 arr[y][z] = 1;
				
			}
		}
	}
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cout << arr[x][y] << " ";
		}
		cout << '\n';
	}

}
int main() {
	int n;
	cin >> n;
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			cin >> arr[x][y];
		}
	}
	floyd(n);
}


