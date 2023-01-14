#include <stdio.h>

int R;
int L;
int pole[50][50];
int N;
FILE * input;
FILE * output;

void printing(){
    int i, j;
    for (i = 0; i < N; i ++){
        for (j = 0; j < N; j ++){
            if (pole[i][j]) fprintf(output, "(%d,%d) ", i, j);
        }
    }
    fprintf(output, "\n");
    R ++;
}

int check(int a, int b){
    for (int i = 0; i < N; ++i){
        if(pole[a][i])
            return 0;
    }
    for(int i = 0; i < N; ++i){
        if(pole[i][b])
            return 0;
    }
    for(int i = 1; a-i >= 0 && b-i >= 0; ++i){
        if(pole[a - i][b - i])
            return 0;
    }
    for(int i = 1; a+i < N && b + i < N; ++i){
        if(pole[a + i][b + i])
            return 0;
    }
    for(int i = 1; a+i < N && b - i >= 0; ++i){
        if(pole[a + i][b - i])
            return 0;
    }
    for(int i = 1; a-i >= 0 && b+i < N; ++i){
        if(pole[a - i][b + i])
            return 0;
    }
    if ((a - 1) >= 0 && (b - 2) >= 0 && pole[a - 1][b - 2])
        return 0;
    if ((a - 1) >= 0 && (b + 2) < N && pole[a - 1][b + 2])
        return 0;
    if ((a + 1) < N && (b - 2) >= 0 && pole[a + 1][b - 2])
        return 0;
    if ((a + 1) < N && (b + 2) < N && pole[a + 1][b + 2])
        return 0;
    if ((a - 2) >= 0 && (b - 1) >= 0 && pole[a - 2][b - 1])
        return 0;
    if ((a - 2) >= 0 && (b + 1) < N && pole[a - 2][b + 1])
        return 0;
    if ((a + 2) < N && (b - 1) >= 0 && pole[a + 2][b - 1])
        return 0;
    if ((a + 2) < N && (b + 1) < N && pole[a + 2][b + 1])
        return 0;
    return 1;
}

void put(int a, int count){
    for(int b = 0; b < N; ++b){
        if(check(a, b)){
            pole[a][b] = 1;
            for(int i = a+1; i < N; ++i) {
                put(i, count + 1);
            }
            if(count+1 == L)
                printing();
            pole[a][b]=0;
        }
    }
}

int main(){
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    int K, x, y;
    fscanf(input, "%d %d %d", &N, &L, &K);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pole[i][j] = 0;
    while(K > 0){
        fscanf(input, "%d %d", &x, &y);
        pole[x][y] = 1;
        K --;
    }
    for (int i=0; i < N; ++i)
        put(i, 0);
    if (R == 0)
        fprintf(output, "no solutions");
}
