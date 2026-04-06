#include <iostream>
#include <vector>

using namespace std;
typedef vector<vector<long long>> Matrix;
int n;
// 행렬 곱셈
Matrix multiply(const Matrix &A, const Matrix &B)
{
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
            {
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= 1000;
            }
        }
    }
    return C;
}
// 분할 정복
Matrix power(Matrix A, long long b)
{
    // 더 이상 나눌 수 없음
    if (b == 1)
        return A;

    // 절반을 구하고, 절반끼리 곱셈을 함
    Matrix half = power(A, b / 2);
    Matrix result = multiply(half, half);

    // 홀수인 경우에는 해당 매트릭스를 한 번더 곱함
    if (b % 2 == 1)
        result = multiply(result, A);
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long b;
    cin >> n >> b;

    // 2차원 행렬 입력 및 선언
    Matrix A(n, vector<long long>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> A[i][j];
            A[i][j] %= 1000;
        }
    }

    Matrix result = power(A, b);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << result[i][j];
            if (j < n - 1)
                cout << ' ';
        }
        cout << '\n';
    }
}