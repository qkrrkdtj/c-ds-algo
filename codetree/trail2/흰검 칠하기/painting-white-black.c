#include <stdio.h>
#include <string.h>

int main() {
    int white[2000001];
    int black[2000001];
    int color[2000001]; // 0: 없음, 1: 흰색, 2: 검은색

    memset(white, 0, sizeof(white));
    memset(black, 0, sizeof(black));
    memset(color, 0, sizeof(color));

    int N;
    scanf("%d", &N);

    int pos = 1000000;

    for(int i = 0; i < N; i++) {
        int x;
        char dir;

        scanf("%d %c", &x, &dir);

        if(dir == 'R') {
            for(int j = pos; j < pos + x; j++) {
                black[j]++;
                color[j] = 2;
            }
            pos += x - 1;
        }
        else {
            for(int j = pos; j > pos - x; j--) {
                white[j]++;
                color[j] = 1;
            }
            pos -= x - 1;
        }
    }

    int w = 0, b = 0, g = 0;

    for(int i = 0; i <= 2000000; i++) {
        if(white[i] >= 2 && black[i] >= 2)
            g++;
        else if(color[i] == 1)
            w++;
        else if(color[i] == 2)
            b++;
    }

    printf("%d %d %d\n", w, b, g);

    return 0;
}