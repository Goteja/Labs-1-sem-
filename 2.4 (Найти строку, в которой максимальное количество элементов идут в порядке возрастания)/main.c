#include <stdio.h>

int main() {
#define N 100
    int m, n, t = 0, a[N][N], v[N], max = 0, i, j, k, te = 0;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    if (m == 1)
        printf("%d", a[n- 1][m - 1]);
    else{
        for (i = 0; i < n; i++) {
            for (k = 0; k < m; k++) {
                for (j = k; j < m; j++){
                    if (a[i][j - 1] >= a[i][j]){
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
                    v[k] = a[i][k];
                }
                max = t;
            }
            t = 0;
        }
        for (i = 0; i < m; i++) {
            printf("%d ", v[i]);
        }
    }
}
