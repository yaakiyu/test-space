#include<stdio.h>
#include <string.h>


void reverse(char* s){
    int i = 0;
    int j = strlen(s) - 1;
    
    while (i < j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}


void add(char* x, char* y, char* ans) {
    reverse(x);
    reverse(y);

    int x_end = 0, y_end = 0; // フラッグ
    int kuriagari = 0;
    int i = 0;
    
    while (x_end == 0 || y_end == 0) {

        int keta = kuriagari;
        if (x_end == 0) keta += (x[i] - '0');
        if (y_end == 0) keta += (y[i] - '0');

        kuriagari = keta / 10;

        ans[i] = (keta % 10) + '0';

        i++;
        if (x[i] == '\0') x_end = 1;
        if (y[i] == '\0') y_end = 1;
    }

    if (kuriagari == 1) {
        // 最後に繰り上がりがあった場合
        ans[i] = kuriagari + '0';
        i++;
    }
    ans[i] = '\0';
    
    reverse(ans);
}


int main() {
    char a[100], b[100];
    printf("1つ目の数字を入力: ");
    scanf("%s", a);
    printf("2つ目の数字を入力: ");
    scanf("%s", b);
    
    char ans[101];
    
    add(a, b, ans);
    
    printf("2つの数字の和は %s\n", ans);
}
