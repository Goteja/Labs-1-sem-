#include <stdio.h>

int main() {
#define N 100
    int m, n, t = 0, v[N], max = 0, i, j, k, te = 0;
    scanf("%d %d", &n, &m);
    int a[N * N];
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &(*(a + i * m + j)));
        }
    }
    if (m == 1)
        printf("%d", *(a + (n - 1) * m + m - 1));
    else{
        for (i = 0; i < n; i++) {
            for (k = 0; k < m; k++) {
                for (j = k; j < m; j++){
                    if (*(a + i * m + j - 1) >= *(a + i * m + j)){
                        te++;
                    }
                    else break;
                }
                if (te > t){
                    t = te;
                }
                te = 0;
            }
            if (t >= max) {
                for (k = 0; k < m; k++) {
                    *(v + k) = *(a + i * m + k);
                }
                max = t;
            }
            t = 0;
        }
        for (i = 0; i < m; i++) {
            printf("%d ", *(v + i));
        }
    }
}
