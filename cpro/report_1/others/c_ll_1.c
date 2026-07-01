#include <stdio.h>

int main() {
    long long n, ans;
    ans = 0;

    printf("Nを入力: ");
    scanf("%ld", &n);

    for (long long i = 1; i <= n; i++) {
        ans += i * i;
    }
    printf("1から%ldまでの平方和は %ld\n", n, ans);

    return 0;
}
