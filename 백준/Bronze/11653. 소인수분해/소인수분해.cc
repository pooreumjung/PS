#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	if (a == 1)
		return 0;
	else
    {for (int x= 2; x<= a; x++) {
			while (a % x == 0)
			{
				cout << x << "\n";
				a /= x;
			}
		}
    }	
	}



