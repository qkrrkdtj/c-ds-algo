#include <stdio.h>

int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);

    int x, y;
    int arr[201][201] = {0};

    for(int i = 0; i < N; i++) {
        scanf("%d%d", &x, &y);
        for(int j = 0; j < 8; j++) {
            for(int k = 0; k < 8; k++) {
                arr[x+j+100][y+k+100]++;
            }
        }
    }
    int cnt = 0;

    for(int a = 0; a < 201; a++) {
        for(int b = 0; b < 201; b++) {
            if(arr[a][b] >= 1) cnt++;
        }
    }

    printf("%d", cnt);

    return 0;
}