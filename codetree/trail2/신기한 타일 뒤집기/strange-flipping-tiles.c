#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int color[2000001];
    memset(color, 0, 2000001*sizeof(int));

    int N;
    scanf("%d", &N);

    int x;
    char dir;
    int zp = 1000000;
    for(int i = 0; i < N; i++) {
        scanf("%d %c", &x, &dir);
        if(dir=='R') {
            for(int j = zp; j < zp + x; j++) {
                color[j] = 1;
            }
            zp += x - 1;
        }
        else {
            for(int j = zp; j > zp - x; j--) {
                color[j] = 2;
            }
            zp -= x - 1;
        }
    }

    int w = 0;
    int b = 0;

    for(int k = 0; k < 2000001; k++) {
        if(color[k] == 1) b++;
        else if(color[k] == 2) w++;
    }

    printf("%d %d", w, b);

    return 0;
}