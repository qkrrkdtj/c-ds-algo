#include <stdio.h>
#define OFFSET 100

int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);

    int arr[201][201] = {0};
    int x1, y1, x2, y2;

    for(int i = 0; i < N; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        if(i%2==0) {
            for(int j = x1 + OFFSET; j < x2 + OFFSET; j++) {
                for(int k = y1 + OFFSET; k < y2 + OFFSET; k++) {
                    arr[j][k] = 1;
                }
            }
        }

        else {
            for(int j = x1 + OFFSET; j < x2 + OFFSET; j++) {
                for(int k = y1 + OFFSET; k < y2 + OFFSET; k++) {
                    arr[j][k] = 2;
                }
            }
        }
    }

    int cnt = 0;

    for(int a = 0; a < 201; a++) {
        for(int b = 0; b < 201; b++) {
            if(arr[a][b]==2) cnt++;
        }
    }

    printf("%d", cnt);
    
    return 0;
}