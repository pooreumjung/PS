#include <iostream>
using namespace std;

int two = 0, five = 0, n;

int main()
{
	cin >> n;
	if (n == 1 || n == 3)       //1이나 3은 나눌 수 없는 경우다
	{
		cout << -1 << endl;
		return 0;
	}
	five = n / 5;               //5원짜리 동전의 개수를 저장
	n = n % 5;                  //n에는 남은 잔돈 저장
	if (n % 2 == 0)             //2로 나눈 나머지가 0인 경우 나누어 떨어지는 경우이므로 바로 계산 후 출력
	{
		two = n / 2;
		cout << five + two << endl;
		return 0;
	}
	else                        //나머지가 0이 아닌경우 5원짜리 동전 하나를 빼고, 잔돈을 짝수로 만들어 계산 후 출력
	{
		n += 5;
		five -= 1;
		two = n / 2;
		cout << five + two << endl;
	}
	return 0;
}