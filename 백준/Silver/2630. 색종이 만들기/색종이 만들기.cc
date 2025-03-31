#include<bits/stdc++.h>
using namespace std;

int arr [129][129];

int zeroCount = 0, oneCount = 0;

void abc(int x,int y, int n) {
    int value = arr[x][y];
    bool isSame = true;

    for (int i = x; i < x+n; i++) {
        for (int j = y; j < y+n; j++) {
            if (arr[i][j]!=value) {
                isSame = false;
                break;
            }
        }
        if (!isSame)
            break;
    }

    if (isSame) { // 모두 같다면
        if (value ==0) zeroCount++;
        else oneCount++;
    }

    else {
        int newSize = n/2;
        abc(x,y,newSize); // 왼쪽 위
        abc(x,y+newSize,newSize); // 오른쪽 위
        abc(x+newSize,y,newSize); // 왼쪽 아래
        abc(x+newSize,y+newSize,newSize); // 오른쪽 아래
    }

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
        }
    }

    abc(0,0,n);
    cout<<zeroCount<<"\n"<<oneCount;
}