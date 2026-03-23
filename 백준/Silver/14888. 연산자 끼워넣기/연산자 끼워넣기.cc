#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, num;
long minResult = 9999999999, maxResult = -999999999;
char opArr[12], opArr2[12];
vector<int> v;
bool visited[12];
int arr[4];
// 초기화 함수
void init(int op, int index)
{
    switch (op)
    {
    case 0:
        opArr[index] = '+';
        break;
    case 1:
        opArr[index] = '-';
        break;
    case 2:
        opArr[index] = '*';
        break;
    case 3:
        opArr[index] = '/';
        break;
    default:
        break;
    }
}
// 계산하기
long calculate(long num1, long num2, char op)
{
    long temp = 0;
    switch (op)
    {
    case '+':
        temp = num1 + num2;
        break;
    case '-':
        temp = num1 - num2;
        break;
    case '*':
        temp = num1 * num2;
        break;
    case '/':
        temp = num1 / num2;
        break;
    default:
        break;
    }

    return temp;
}
void dfs(int depth)
{
    if (depth == N - 1)
    {
        int index = 0;
        long sum = 0;
        for (int i = 0; i < N; i++)
        {
            if (i == 0)
                sum = v[i];
            else
            {
                sum = calculate(sum, v[i], opArr2[index]);
                index++;
            }
        }
        minResult = min(minResult, sum);
        maxResult = max(maxResult, sum);
        return;
    }

    for (int i = 0; i < N - 1; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            opArr2[depth] = opArr[i];
            dfs(depth + 1);
            opArr2[depth] = ' ';
            visited[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정수 배열 입력
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        v.push_back(num);
    }

    // 문자 배열 초기화
    int index = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
        for (int j = 0; j < arr[i]; j++)
        {
            init(i, index);
            index++;
        }
    }

    dfs(0);
    cout << maxResult << '\n'
         << minResult;
}