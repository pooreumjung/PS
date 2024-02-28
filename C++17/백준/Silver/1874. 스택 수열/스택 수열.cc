#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; // 배열의 크기
	cin >> n;

	vector<int>A(n, 0); // 입력 받을 배열
	vector<char>result; // 결과 출력 배열

	int num = 1;// push할 자연수
	stack<int>myArr; // 스택
	bool check = true; // NO의 판단법
	
	for (int i = 0; i < n; i++) {
		cin >> A[i]; // 배열 입력
	}

	for (int i = 0; i < A.size(); i++) {
		
		int su = A[i]; // 현재 배열의 값

		if (su >= num) { // 배열의 값이 num보다 크다면
			
			while (su >= num) {  
				myArr.push(num);
				num++;
				result.push_back('+');
			}
			
			myArr.pop();
			result.push_back('-');
		}
		
		else {
			
			int dx = myArr.top();
			myArr.pop();
			
			if (dx > su) {
				cout << "NO";
				check = false;
				break;
			}
			
			else {
				result.push_back('-');
			}
		}
	}

	if (check) {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] << '\n';
		}
	}
}