#include<iostream>
#include<string>
using namespace std;
string str;
string map[8] = { "c=","c-","dz=",
"d-","lj","nj","s=","z="
};
int find(int k);
int main() {
	cin >> str;
	int cnt = 0;
	int len2 = str.length();
	for (int x = 0; x < 8; x++) {
		int len = find(x);
		cnt += len;
	}
	
	cout << len2-cnt;
}
int find(int k) {
	int a = 0, b = 0, cnt = 0;
	while (1) {
		int res = str.find(map[k], b);
		if (res == -1)
			break;
			cnt++;
			b = res + 1;
	}
	return cnt;



}
