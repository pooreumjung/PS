#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second) {
    if (*(int*)first > *(int*)second) return 1;
    else if (*(int*)first < *(int*)second) return -1;
    else return 0;
}
void result(int *arr, int n, int x) {
    int min = 0, max = n - 1;
    while (min <= max) {
        int mid = (min + max) / 2;
        if (arr[mid] == x) {
            printf("%d\n", 1);
            return;
        }
        else if (arr[mid] > x) max = mid - 1;
        else min = mid + 1;
    }
    printf("%d\n", 0);
    return;
}
int main() {
    int n, m, num;
    scanf("%d", &n);
    int *arr= (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    qsort(arr, n, sizeof(int), compare);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        result(arr,n,num);
    }
    return 0;
}
