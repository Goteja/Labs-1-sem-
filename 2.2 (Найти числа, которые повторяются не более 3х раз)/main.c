#include <stdio.h>

int main()
{
    int n, s = 0, t = -1, i, flag = 0, sum = 0;
    scanf("%d", &n);
    int a[10000], b[10000], c[10000];

    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    while(s < n){
        for(i = 0; i <= t; i++){
            if(a[s] == b[i]){
                flag = 1;
                c[i] ++;
            }
            }
        if(flag == 0){
            t ++;
            b[t] = a[s];
            c[t] = 1;
        }
        s++;
        flag = 0;
    }
    for(i = 0; i <= t; i++){
        if(c[i] <= 3){
            sum++;
        }
    }
    printf("%d", sum);
}