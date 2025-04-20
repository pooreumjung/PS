#include<bits/stdc++.h>
using namespace std;

bool arr[101][101];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test=4,area=0;
    while (test--) {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;

        for (int i=x1;i<x2;i++) {
            for (int j=y1;j<y2;j++) {
                arr[i][j]=true;
            }
        }
    }

    for (int i=0;i<101;i++) {
        for (int j=0;j<101;j++) {
            if (arr[i][j])
                area++;
        }
    }

    cout<<area;
}