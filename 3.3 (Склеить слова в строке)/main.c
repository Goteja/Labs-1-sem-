#include <stdio.h>
#include <string.h>

int main(){
    int i, j, n, t, k, l, flag, f;
    scanf("%d\n", &n);
    char str[80][80];
    char s1[40], s2[40];
    for (i = 0; i < n; i++){
        gets(str[i]);
    }
    for (i = 0; i < n; i++){
        t = 0;
        flag = 0;
        for (j = 0; j < strlen(str[i]); j++){
            if (flag == 0 && str[i][j] != ' '){
                s1[j] = str[i][j];
                k = j;
            }
            if (flag == 1 && str[i][j] != ' '){
                s2[t] = str[i][j];
                t++;
            }
            if (str[i][j] == ' '){
                flag = 1;
            }
        }
        s1[k + 1] = '\0';
        s2[t] = '\0';
        for (l = 0; l < strlen(s1); l ++){
            f = 1;
            for (j = 0; j < strlen(s1) - l; j ++){
                if (s1[l + j] != s2[j]){
                    f = 0;
                    break;
                }
            }
            if (f == 1) {
                s1[l] = '\0';
                break;
            }
        }
        printf("%s%s\n", s1, s2);
    }
}