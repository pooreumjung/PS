#include <iostream>
using namespace std;
int main(void){
    int a;
    cin >> a;
    for(int i=0;i<a;i++)
    {
	   for(int j=0;j<i;j++){
	      cout << ' ';
	}
	for(int b=i+1;b<a*2-i;b++){
	    cout << '*';
	}
	cout << endl;
    }
    return 0;
}
