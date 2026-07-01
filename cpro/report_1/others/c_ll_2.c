#include <stdio.h>

int main() {
    long long n;

    printf("Nを入力: ");
    scanf("%ld", &n);

    printf("1から%ldまでの平方和は %ld\n", n, n * (n + 1) * (2 * n + 1) / 6);

    return 0;
}
