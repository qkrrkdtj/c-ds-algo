#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int white[2000001];
    int black[2000001];
    int color[2000001];
    memset(white, 0, 2000001*sizeof(int));
    memset(black, 0, 2000001*sizeof(int));
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
                black[j]++;
                color[j] = 2;
            }
            zp += x - 1;
        }
        else {
            for(int j = zp; j > zp - x; j--) {
                white[j]++;
                color[j] = 1;
            }
            zp -= x - 1;
        }
    }
    int w = 0;
    int b = 0;
    int g = 0;
    for(int k = 0; k < 2000001; k++) {
        if(white[k]>=2 && black[k]>=2) g++;
        else if(color[k] == 1) w++;
        else if(color[k] == 2) b++;
    }

    printf("%d %d %d", w, b, g);
    
    return 0;
}