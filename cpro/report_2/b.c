#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int is_in_circle(double x, double y) {
    if ((x*x + y*y) <= 1.0) return 1;
    return 0;
}



int main(){
    // 初期化
    srand((unsigned int)time(NULL));

    int n;
    printf("Nを入力: ");
    scanf("%d", &n);
    
    int count = 0;

    for (int i = 0; i < n; i++) {
        double x = (double)rand() / RAND_MAX;
        double y = (double)rand() / RAND_MAX;

        count += is_in_circle(x, y);
    }

    printf("円周率の近似値は %lf\n", (double)(4 * count) / (double)n);

    return 0;
}
