#include <stdio.h>
void hanoi(int n, int a, int b) {
    if (n == 0) return;
	
    hanoi(n - 1, a, 6 - a - b);
	printf("%d %d\n", a, b);
    hanoi(n - 1, 6 - a - b, b);
}
int main() {
    int num;
    int count = 1;
	scanf("%d", &num);

    for (int x = 0; x < num; x++) {
        count *= 2;
    }
	printf("%d\n", count - 1);
    hanoi(num, 1, 3);

    return 0;
}

