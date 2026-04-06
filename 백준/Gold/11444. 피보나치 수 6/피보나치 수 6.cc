#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1e9 + 7;

Matrix multiply(const Matrix &A, const Matrix &B)
{
    int n = A.size();
    Matrix C(n, vector<ll>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix power(Matrix A, ll b)
{
    if (b == 1)
        return A;

    Matrix half = power(A, b / 2);
    Matrix result = multiply(half, half);

    if (b % 2 == 1)
        result = multiply(result, A);

    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    if (n == 1)
    {
        cout << 1;
        return 0;
    }

    Matrix A = {{1, 1}, {1, 0}};
    Matrix result = power(A, n - 1);

    cout << result[0][0];
}