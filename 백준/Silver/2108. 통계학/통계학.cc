#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[8001];
int arr2[500001];
int result;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int num, max2 = -4001, min2 = 9998, count1 = 0, index, max1 = -1;
	double sum = 0;
	cin >> num;
	for (int x = 0; x < num; x++) {
		cin >> arr2[x];
		arr[arr2[x] + 4000] += 1;
		sum += arr2[x];
	}
	sum /= (double)num;
	sum = floor(sum + 0.5);
	sort(arr2, arr2+num);
	for (int x = 0; x < 8001; x++) {
		if (max1 < arr[x])
			max1 = arr[x];
	}
	for (int x = 0; x < 8001; x++) {
		if (max1 == arr[x]) {
			count1++;
			index = x;
		}
		if (count1 == 2)
			break;
	}
	printf("%0.lf\n%d\n%d\n%d\n", sum, arr2[num/2],index-4000 , arr2[num-1]-arr2[0]);
}