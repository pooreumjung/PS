#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin>>n;
	vector<int> temp;
	vector<vector<int>> triangle;
	int one;
	
	for(int i = 1; i<=n; i++){
		temp.clear();
		for(int j = 0; j<i; j++){
			cin>>one;
			temp.push_back(one);
		}
		triangle.push_back(temp);
	}
	
	
	for(int i = n-1; i>0; i--){
		// j를 0부터 n-2까지 키우며
		for(int j = 0; j<triangle[i].size()-1; j++){
			//j와 j+1중 크기가 더 큰걸 누적해 더해나간다.
			if(triangle[i][j]>=triangle[i][j+1]){
				triangle[i-1][j] += triangle[i][j];
			}
			else{
				triangle[i-1][j] += triangle[i][j+1];
			}
			
		}
		
	}

	
	cout<<triangle[0][0];
	
}
