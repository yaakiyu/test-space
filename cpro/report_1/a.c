#include <stdio.h>
#define yes "す\n"
#define no "ではありません\n"


int main() {
    int n;

    printf("年を入力: ");
    scanf("%d", &n);

    printf("%d年はうるう年で", n);
    if (n % 4 != 0) {
        printf(no);
        return 0;
    }
    if (n % 400 == 0) {
        printf(yes);
        return 0;
    }
    if (n % 100 == 0) {
        printf(no);
        return 0;
    }
    printf(yes);

    return 0;
}
