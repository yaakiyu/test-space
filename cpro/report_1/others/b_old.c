#include <stdio.h>


int searchsqrt(int mx) {
    // 二分探索によって平方根を探す
    int ok = mx;
    int ng = 1;
    while (ok > ng + 1) {
        int mid = (ok + ng) / 2;
        if (mid * mid > mx) {
            ok = mid;
        }
        else {
            ng = mid;
        }
    }
    return ng;
}


void main() {
    int n;
    int ans_found = 0;  // 答えが見つかったら1

    printf("Nを入力: ");
    scanf("%d", &n);

    for (int a=1; a <= n; a++) {
        for (int b = a+1; b <= n; b++) {
            int cc = a*a + b*b;
            if (cc > n*n) {
                break;
            }

            int c = searchsqrt(cc);
            if (c*c == cc){
                ans_found = 1;
                printf("(%d, %d, %d)\n", a, b, c);
            }
        }
    }

    if (ans_found == 0) {
        printf("見つかりませんでした。\n");
    }
}
