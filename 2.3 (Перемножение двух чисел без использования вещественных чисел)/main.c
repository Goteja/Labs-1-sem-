#include <stdio.h>

int power(int x){
    if (x == 0) return 1;
    if (x == 1) return 10;
    if (x == 2) return 100;
    if (x == 3) return 1000;
    if (x == 4) return 10000;
    else return 0;
}

int main() {
    char a[9];
    int a1, a2, s, t, v1, v2, z = 0, num1, num2;

    scanf("%s", a);
    num1 = ((a[0] - '0') * 100 + (a[2] - '0') * 10 + (a[3] - '0'));
    num2 = ((a[5] - '0') * 100 + (a[7] - '0') * 10 + (a[8] - '0'));
    t = num1 * num2;
    while((t < 1000) && (t != 0)){
        t *= 10;
        z += 1;
    }
    if (a[2] != '0'){
        if (a[3] != '0'){
            s = 2;
            a1 = ((a[0] - '0') * 100) + ((a[2] - '0') * 10) + (a[3] - '0');
        }
        else {
            s = 1;
            a1 = ((a[0] - '0') * 10) + (a[2] - '0');
        }
    }
    else {
        if (a[3] != '0'){
            s = 2;
            a1 = ((a[0] -'0') * 100) + (a[3] - '0');
        }
        else{
            s = 0;
            a1 = (a[0] - '0');
        }
    }
    if (a[7] != '0'){
        if (a[8] != '0'){
            s += 2;
            a2 = ((a[5] - '0') * 100) + ((a[7] - '0') * 10) + (a[8] - '0');
        }
        else {
            s += 1;
            a2 = ((a[5] - '0') * 10) + (a[7] - '0');
        }
    }
    else {
        if (a[8] != '0'){
            s += 2;
            a2 = ((a[5] -'0') * 100) + (a[8] - '0');
        }
        else{
            s += 0;
            a2 = (a[5] - '0');
        }
    }
    t = a1 * a2;
    s = power(s);
    v1 = t / s;
    v2 = t % s;
    if (v2 == 0)
        printf("%d", v1);
    else{
        printf("%d.", v1);
        if (z == 1) printf("0");
        if (z == 2) printf("00");
        if (z == 3) printf("000");
        printf("%d", v2);
    }
}

