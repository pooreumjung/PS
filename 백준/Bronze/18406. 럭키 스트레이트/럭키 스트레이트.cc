#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string N;
	cin >> N;
	int result = 0;

	for (int i = 0; i < N.length() / 2; i++)
		result += (N[i] - N[i + N.length() / 2]);

	if (result == 0)
		cout << "LUCKY";
	else
		cout << "READY";
}