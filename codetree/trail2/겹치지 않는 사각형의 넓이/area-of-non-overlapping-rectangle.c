#include <stdio.h>

int main() {
    // Please write your code here.
    int x[2001][2001] = {0};
    int x1, y1, x2, y2;

    for(int i = 0; i < 3; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(i < 2) {
            for(int j = x1 + 1000; j < x2 + 1000; j++) {
                for(int k = y1 + 1000; k < y2 + 1000; k++) {
                    x[j][k]++;
                }
            }
        }
        else {
            for(int j = x1 + 1000; j < x2 + 1000; j++) {
                for(int k = y1 + 1000; k < y2 + 1000; k++) {
                    x[j][k]=0;
                }
            }
        }
    }

    int cnt = 0;

    for(int a = 0; a < 2001; a++) {
        for(int b = 0; b < 2001; b++) {
            if(x[a][b] >= 1) cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}