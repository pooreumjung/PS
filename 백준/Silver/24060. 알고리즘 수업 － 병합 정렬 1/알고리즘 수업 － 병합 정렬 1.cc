#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int temp[500001];
int N, K, num, total = 0, result = -1;

void merge(vector<int> &v, int p, int q, int r)
{
    int i = p, j = q + 1, t = 1;

    while (i <= q and j <= r)
    {
        if (v[i] <= v[j])
            temp[t++] = v[i++];
        else
            temp[t++] = v[j++];
    }

    while (i <= q)
        temp[t++] = v[i++];
    while (j <= r)
        temp[t++] = v[j++];

    i = p;
    t = 1;

    while (i <= r)
    {
        v[i] = temp[t];
        total++;

        if (total == K)
            result = v[i];

        t++;
        i++;
    }
}

void merge_sort(vector<int> &v, int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        merge_sort(v, p, q);
        merge_sort(v, q + 1, r);
        merge(v, p, q, r);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    merge_sort(v, 0, N - 1);
    cout << result;
}