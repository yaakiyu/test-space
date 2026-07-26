#include<stdio.h>
#include<string.h>


// 文字列関連の関数
void strcopy(char* a, char* b) {
    // aの内容をbにコピーする
    int i = 0;
    while (a[i] != '\0') {
        b[i] = a[i];
        i++;
    }
    b[i] = '\0';
}

void reverse(char* s){
    // 文字列を反転させる
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


struct Number {
    char value[100];
    int length;
    int sign; // 正なら1, 負なら-1
};

// Number関連の関数
void set_number(struct Number* num, char* str) {
    num->sign = (str[0] == '-') ? -1 : 1;
    if (num->sign == -1) {
        strcopy(str + 1, num->value); // '-'を除いた部分をコピー
    } else {
        strcopy(str, num->value);
    }
    num->length = strlen(num->value);
    reverse(num->value); // 計算のために反転させる
}

void get_number_string(struct Number* num, char* str) {
    int pos = 0;
    if (num->sign == -1) {
        str[pos] = '-';
        pos++;
    }

    for (int i = num->length - 1; i >= 0; i--) {
        str[pos] = num->value[i];
        pos++;
    }

    str[pos] = '\0';
}


int bigger(struct Number x, struct Number y) {
    // xがy以上の場合は1, 小さい場合は0を返す

    // 符号処理
    if (x.sign > y.sign) return 1;
    if (x.sign < y.sign) return 0;
    // 両方ともマイナスの場合はxとyを入れ替える
    if (x.sign == -1) {
        struct Number temp = x;
        x = y;
        y = temp;
    }

    int x_len = x.length;
    int y_len = y.length;

    if (x_len > y_len) return 1;
    if (x_len < y_len) return 0;

    for (int i = x_len - 1; i >= 0; i--) {
        if (x.value[i] > y.value[i]) return 1;
        if (x.value[i] < y.value[i]) return 0;
    }

    return 1;
}


void add(struct Number x, struct Number y, struct Number* ans) {
    // x + yを計算する
    int x_end = 0, y_end = 0; // フラッグ
    int kuriagari = 0;
    int i = 0;
    
    while (x_end == 0 || y_end == 0) {
        int keta = kuriagari;
        if (x_end == 0) keta += (x.value[i] - '0');
        if (y_end == 0) keta += (y.value[i] - '0');

        kuriagari = keta / 10;

        ans->value[i] = (keta % 10) + '0';

        i++;
        if (x.value[i] == '\0') x_end = 1;
        if (y.value[i] == '\0') y_end = 1;
    }

    if (kuriagari == 1) {
        // 最後に繰り上がりがあった場合
        ans->value[i] = kuriagari + '0';
        i++;
    }
    ans->value[i] = '\0';
}


void sub(struct Number x, struct Number y, struct Number* ans) {
    // x - yを計算する
    if (bigger(x, y) == 0) {
        // x < yの場合は符号を反転させる
        sub(y, x, ans);
        ans->sign = -1;
        return;
    }

    ans->sign = 1;
    int x_end = 0, y_end = 0; // フラッグ
    int hiku = 0;
    int i = 0;
    
    while (x_end == 0 || y_end == 0) {
        int keta = (x_end == 0 ? (x.value[i] - '0') : 0) - hiku;
        if (y_end == 0) keta -= (y.value[i] - '0');

        if (keta < 0) {
            keta += 10;
            hiku = 1;
        } else {
            hiku = 0;
        }

        ans->value[i] = keta + '0';

        i++;
        if (x.value[i] == '\0') x_end = 1;
        if (y.value[i] == '\0') y_end = 1;
    }

    ans->length = i;
    if (ans->value[i-1] == '0') {
        ans->value[i-1] = '\0';
        ans->length--;
    } else {
        ans->value[i] = '\0';
    }
}


int main() {
    struct Number a, b, ans;
    char a_str[100], b_str[100], ans_str[101];
    printf("1つ目の数字を入力: ");
    scanf("%s", a_str);
    printf("2つ目の数字を入力: ");
    scanf("%s", b_str);

    set_number(&a, a_str);
    set_number(&b, b_str);

    sub(a, b, &ans);

    get_number_string(&ans, ans_str);
    printf("2つの数字の差は %s\n", ans_str);
}
