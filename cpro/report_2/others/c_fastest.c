#include<stdio.h>

const int lutable[] = {
    0, 0, 0, 0,  // 0
    1, 0, 0, 0,  // 110
    0, 1, 0, 0,  // 180
    2, 0, 0, 0,  // 220
    0, 0, 0, 1,  // 260
    1, 0, 0, 1,  // 370
    0, 0, 1, 0,  // 410
    0, 1, 0, 1,  // 440
    2, 0, 0, 1   // 480
    // 1個につきそれぞれans[0]が3, 5, 15, 11上昇する
};


int main() {
    int n;
    printf("金額を入力: ");
    scanf("%d", &n);

    // パターン1: 最大まで4番目を買う
    int amari = n % 260;
    int syou = n / 260;

    int ans[5] = {syou * 11, 0};  // 価格、あまりのパターン

    if (amari >= 110) {
        if (amari >= 180) {
            if (amari >= 220) {
                ans[0] += 6;
                ans[1] = 3;
            } else {
                ans[0] += 5;
                ans[1] = 2;
            }
        } else {
            ans[0] += 3;
            ans[1] = 1;
        }
    }

    // パターン2: 最大-1まで4番目を買う
    if (syou > 0) {
        int amari2 = amari + 260;
        int ans2[5] = {(syou - 1) * 11, 0};  // 価格、あまりのパターン

        if (amari2 >= 410) {
            if (amari2 >= 440) {
                if (amari2 >= 480) {
                    ans2[0] += 17;
                    ans2[1] = 8;
                } else {
                    ans2[0] += 16;
                    ans2[1] = 7;
                }
            } else {
                ans2[0] += 15;
                ans2[1] = 6;
            }
        } else {
            if (amari2 >= 370) {
                ans2[0] += 14;
                ans2[1] = 5;
            } else {
                ans2[0] += 11;
                ans2[1] = 4;
            }
        }

        if (ans2[0] > ans[0]) {
            ans[0] = ans2[0];
            ans[1] = ans2[1];
        }
    }

    int i = ans[1]*4;

    int dess = ans[1] > 3 ? syou - 1 : syou;
    // printf("! %d, %d\n", amari, ans[1]);

    printf(
        "満足度の最大値は %d\nおにぎり %d個, サンドイッチ %d個, お弁当 %d個, デザート %d個 (合計 %d円)\n",
        ans[0], lutable[i], lutable[i + 1], lutable[i + 2], dess + lutable[i + 3],
        (lutable[i]*110 + lutable[i + 1]*180 + lutable[i + 2]*410 + (dess + lutable[i + 3])*260)
    );

    return 0;
}
