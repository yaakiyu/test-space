#include <stdio.h>

int main() {
    int n, ans;
    ans = 0;
    
    printf("Nを入力: ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        ans += i * i;
    }
    printf("1から%dまでの平方和は %d\n", n, ans);
    
    return 0;
}
