#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    int num[1000005];
    vector<int> idx;    
    scanf("%d", &N);   
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
        idx.push_back(num[i]);
    }    
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());    
    for(int i = 0; i < N; i++)
        printf("%d ", lower_bound(idx.begin(), idx.end(), num[i]) - idx.begin());    
    return 0;
}