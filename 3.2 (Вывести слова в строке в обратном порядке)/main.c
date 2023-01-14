#include <stdio.h>
#include <string.h>

int main() {
    char str[100], temp[100][100];
    int i, t = 0, s = 0, j = 0;
    gets(str);
    for (i = 0; i < strlen(str); i ++){
        if (str[i] != ' '){
            temp[t][s] = str[i];
            s ++;
        }
        else{
            t ++;
            temp[t][s + 1] = '\0';
            s = 0;
            j ++;
        }
    }
    for (i = j; i >= 0; i --){
        printf("%s ", temp[i]);
    }
}
