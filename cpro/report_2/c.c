#include<stdio.h>


int main() {
    int n;
    printf("金額を入力: ");
    scanf("%d", &n);

    int ans[5] = {0, 0, 0, 0, 0};  // 価格、i～lの値
    int p;

    for (int i = 0; i <= (n / 110); i++) {
        for (int j = 0; j <= ((n - i*110) / 180); j++) {
            for (int k = 0; k <= ((n - i*110 - j*180) / 410); k++) {
                int l = (n - i*110 - j*180 - k*410) / 260;
                int man = i*3 + j*5 + k*15 + l*11;
                if (man > ans[0]) {
                    ans[0] = man;
                    ans[1] = i;
                    ans[2] = j;
                    ans[3] = k;
                    ans[4] = l;
                }
                p++;
            }
        }
    }

    printf(
        "満足度の最大値は %d\nおにぎり %d個, サンドイッチ %d個, お弁当 %d個, デザート %d個 (合計 %d円)\n",
        ans[0], ans[1], ans[2], ans[3], ans[4], (ans[1]*110 + ans[2]*180 + ans[3]*410 + ans[4]*260)
    );
    printf("計算回数: %d\n", p);

    return 0;
}
