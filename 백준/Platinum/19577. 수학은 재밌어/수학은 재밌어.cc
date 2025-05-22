#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int euler_phi(int n);
int compare(const void *first, const void *second) {
  if (*(int *)first > *(int *)second)
    return 1;
  else if (*(int *)first < *(int *)second)
    return -1;
  else
    return 0;
}

int main(void) {
  int n, x;
  scanf("%d", &n);
  int a[100000] = {0};
  int b[100000] = {0};
  int k = 0;
  for (int i = 1; i <= (int)sqrt(n); i++) // sqrt(n)까지 n 약수들 구하기
    if (n % i == 0) {
      a[k] = i;
      k++;
    }

  for (int i = 0; i < k; i++) { // n을 각 수들로 나눠서 나머지 약수들 구해주기
    b[i] = a[i];
    b[k + i] = n / a[i];
  }

    b[2*k]=n;
  qsort(b, (2 * k)+1, sizeof(int), compare); //약수들 오름차순으로 정렬 (중복그냥 냅둠)

   int cnt = 0;
    for (int i = 0; i <= 2 * k; i++) {
      cnt++;
      if (n == b[i] * euler_phi(b[i])) {
        printf("%d\n", b[i]);
        break;
      }
    }

    if (cnt == ((2 * k)+1))
      printf("-1\n");

  return 0;
}
int euler_phi(int n) {
  int a = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) a = a / i * (i - 1);
    while (n % i == 0) n = n / i;
  }
  return n == 1 ? a : a / n * (n - 1);
}


