#include <stdio.h>


void print_all_triples(int a, int b, int c, int n) {
    // a < b < c になるように並び替え
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b > c) {
        int temp = b;
        b = c;
        c = temp;
    }

    // cがN以下ならa,bもN以下
    int k = 1;
    while (c * k <= n) {
        printf("(%d, %d, %d)\n", a * k, b * k, c * k);
        k++;
    }
}


// DFSで原始ピタゴラス数の三分木を探索
void find_genshi_pitagorasu(int a, int b, int c, int n) {
    if (a > n || b > n || c > n) {
        return;  // 探索終了
    }

    print_all_triples(a, b, c, n);
    
    // Uの遷移
    int u_a = a - 2 * b + 2 * c;
    int u_b = 2 * a - b + 2 * c;
    int u_c = 2 * a - 2 * b + 3 * c;
    find_genshi_pitagorasu(u_a, u_b, u_c, n);
    
    // Aの遷移
    int a_a = a + 2 * b + 2 * c;
    int a_b = 2 * a + b + 2 * c;
    int a_c = 2 * a + 2 * b + 3 * c;
    find_genshi_pitagorasu(a_a, a_b, a_c, n);
    
    // Dの遷移
    int d_a = -a + 2 * b + 2 * c;
    int d_b = -2 * a + b + 2 * c;
    int d_c = -2 * a + 2 * b + 3 * c;
    find_genshi_pitagorasu(d_a, d_b, d_c, n);
}


int main() {
    int n;
    
    printf("Nを入力: ");
    scanf("%d", &n);
    
    if (n < 5) {
        printf("見つかりませんでした。\n");
    }
    else {
        find_genshi_pitagorasu(3, 4, 5, n);
    }

    return 0;
}
