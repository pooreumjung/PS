#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[2000000], arr2[2000000];
int n, k;
vector<int> result;
void merge(int left, int right, int member)
{
    int mid = (left + right) / 2;
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            arr2[k++] = arr[i++];
        else
            arr2[k++] = arr[j++];
    }

    while (i <= mid)
        arr2[k++] = arr[i++];
    while (j <= right)
        arr2[k++] = arr[j++];

    for (int i = left; i <= right; i++)
        arr[i] = arr2[i];
    if (member == (right - left + 1))
    {
        for (int i = left; i <= right; i++)
            cout << arr[i] << " ";
    }
}
void partition(int left, int right, int member)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        partition(left, mid, member);
        partition(mid + 1, right, member);
        merge(left, right, member);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    int member = n / k;
    partition(0, n - 1, member);
}
