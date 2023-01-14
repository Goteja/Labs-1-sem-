#include <stdio.h>

#define max 101

int main(void) {
    int t;
    char str[max], a[max];
    gets(str);
    t = 1;
    a[0] = str[0];
    for (int i = 1; i <= max; i++){
        if (str[i] != str[i - 1]){
            a[t] = str[i];
            a[t+1] = '/0';
            t ++;
        }
    }
    for (int i = 0; i <= max; i++){
        if (a[i] == 0) break;
        printf("%c", a[i]);
    }

}
