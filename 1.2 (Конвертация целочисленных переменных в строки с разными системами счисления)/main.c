#include <stdio.h>
#include <string.h>

void reverse(char *S)
{
    int i, j, l;
    char t;
    l = strlen(S);
    i=0;
    j=l-1;
    while (i<j){
        t=S[i];
        S[i]=S[j];
        S[j]=t;
        i++;j--;
    }
}

void toSS(char *str, long long int ab, int ss){
    long long int t;
    int i = 0, tmp, flag = 0;
    t = ab;
    if (t < 0){
        t *= -1;
        flag = 1;
    }
    while (t > 0){
        tmp = t % ss;
        if (tmp < 10) str[i] = (char)(tmp + '0');
        else{
            str[i] = tmp + 87;
        }
        t /= ss;
        i ++;
    }
    if (flag == 1){
        str[i] = '-';
        i ++;
    }
    str[i] = '\0';
    reverse(str);
}

int main()
{
    int b1 = 34, b2 = 6, b3 = 31, b4 = 7, b5 = 15;
    char str[32];
    short a1 = -0xAA2;
    int a2 = -0x21AB0802;
    unsigned int a3 = 0x5F04C788;
    long a4 = 0x3BCEA81E;
    unsigned long a5 = 0x843CBB50;
    toSS(str, a1, 16);
    printf("short;%s=", str);
    toSS(str, a1, b1);
    printf("%s;%d\n", str, b1);
    toSS(str, a2, 16);
    printf("int;%s=", str);
    toSS(str, a2, b2);
    printf("%s;%d\n", str, b2);
    toSS(str, a3, 16);
    printf("unsigned int;%s=", str);
    toSS(str, a3, b3);
    printf("%s;%d\n", str, b3);
    toSS(str, a4, 16);
    printf("long;%s=", str);
    toSS(str, a4, b4);
    printf("%s;%d\n", str, b4);
    toSS(str, a5, 16);
    printf("unsigned long;%s=", str);
    toSS(str, a5, b5);
    printf("%s;%d", str, b5);
}