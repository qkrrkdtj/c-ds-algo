#include <stdio.h>
#include <string.h>
#define SIZE 2001
#define OFFSET 1000

int main() {
    // Please write your code here.
    int x[SIZE][SIZE]={0};
    //memset(x, 0, sizeof(x));

    int N;
    scanf("%d", &N);
    int x1, x2, y1, y2;
    for(int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        x1+=OFFSET;
        x2+=OFFSET;
        y1+=OFFSET;
        y2+=OFFSET;
        for(int j = x1; j < x2; j++) {
            for(int k = y1; k < y2; k++) {
                x[j][k]++;
            }
        }
        
    }

    int cnt = 0;

    for(int a = 0; a < SIZE; a++) {
        for(int b = 0; b < SIZE; b++) {
            if(x[a][b] >= 1) cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}