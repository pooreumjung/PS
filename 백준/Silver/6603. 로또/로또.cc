#include<iostream>
using namespace std;
int arr[13];
int arr2[14];
int n, m;
void abc(int a, int b);
int main() {
	
	while (1){
		cin >> n;
	if (n == 0)
		break;
	for (int x = 0; x < n; x++)
		cin >> arr[x];
	abc(0, 0);
       cout<<"\n";
}
}
void abc(int a, int b) {
	if (a == 6) {
		for (int x = 0; x < 6; x++)
			cout << arr2[x] << " ";
			cout << "\n";
		return;
	}
	for (int x = b; x < n; x++) {
			arr2[a] = arr[x];
			abc(a + 1, x + 1);
			
	}


}