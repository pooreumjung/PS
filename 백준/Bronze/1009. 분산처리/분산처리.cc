#include<iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int a, b, res;
		cin >> a >> b;
		res = 1; // res를 1로 초기화 해서 b-1번이 아닌 b번만큼 반복문이 돌아도 됨
		for (int i = 0; i < b; i++) {//요부분 i를 최초 0으로 잡아서 b가 1인 경우에도 들어감
			res = (res * a) % 10;
		}
		if (res == 0)
			res = 10;
		cout << res << endl;
	}

}