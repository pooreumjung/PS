#include<iostream>
using namespace std;
int a, b;
int arr[1000001] = { 1,1,0 };
void find(int a, int b);
int main() {
	cin >> a >> b;
	find(a, b);
}
void find(int a, int b) {

	for (int x = 2; x < 1000001/x; x++) {
		if (arr[x] == 1)
			continue;
		for (int y = x *x; y <1000001; y += x)
			if(y%x==0)
			arr[y] = 1;
	}
	for (int x = a; x <= b; x++) {
		if (arr[x] == 0)
			cout << x << "\n";
	}


}