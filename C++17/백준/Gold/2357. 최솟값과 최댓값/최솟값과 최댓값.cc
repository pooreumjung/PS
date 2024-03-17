#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

vector<long>treeMin;
vector<long>treeMax;
void setMin(int i);
void setMax(int i);
long getMin(int start, int end);
long getMax(int start, int end);
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	int length = N;
	int treeHeight = 0;
	while (length != 0) {
		length /= 2;
		treeHeight++;
	}
	int treeSize = int(pow(2, treeHeight + 1));
	int nodeLeftStatrIndex = treeSize / 2 - 1;
	treeMin.resize(treeSize + 1);
	treeMax.resize(treeSize + 1);
	fill(treeMin.begin(), treeMin.end(), LONG_MAX);

	for (int i = nodeLeftStatrIndex + 1; i <= N + nodeLeftStatrIndex; i++) {
		cin >> treeMin[i];
		treeMax[i] = treeMin[i];
	}
	
	setMin(treeSize - 1);
	setMax(treeSize - 1);


	for (int i = 0; i < M; i++) {
		int start, end;
		cin >> start >> end;
		start += nodeLeftStatrIndex;
		end += nodeLeftStatrIndex;
		cout << getMin(start, end) << " " << getMax(start, end) << '\n';
	}
}
void setMin(int i) {
	while (i != 1) {
		treeMin[i / 2] = min(treeMin[i / 2], treeMin[i]);
		i--;
	}
}
void setMax(int i) {
	while (i != 1) {
		treeMax[i / 2] = max(treeMax[i / 2], treeMax[i]);
		i--;
	}
}
long getMin(int start, int end) {
	long partMin = 1000000001;
	while (start <= end) {
		if (start % 2 == 1) {
			partMin = min(partMin, treeMin[start]);
			start++;
		}
		if (end % 2 == 0) {
			partMin = min(partMin, treeMin[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return partMin;
}
long getMax(int start, int end) {
	long partMax = 0;
	while (start <= end) {
		if (start % 2 == 1) {
			partMax = max(partMax, treeMax[start]);
			start++;
		}
		if (end % 2 == 0) {
			partMax = max(partMax, treeMax[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return partMax;

}