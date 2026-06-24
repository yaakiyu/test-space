#include <stdio.h>

int main() {
    int n;
    
    printf("Nを入力: ");
    scanf("%d", &n);
    
    printf("1から%dまでの平方和は %d\n", n, n * (n + 1) * (2 * n + 1) / 6);
    
    return 0;
}
