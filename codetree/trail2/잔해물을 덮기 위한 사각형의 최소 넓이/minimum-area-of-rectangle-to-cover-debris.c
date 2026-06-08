#include <stdio.h>
#define OFFSET 1000

int main() {
    // Please write your code here.
    int x11, x12, y11, y12;
    scanf("%d%d%d%d", &x11, &y11, &x12, &y12);
    int x21, x22, y21, y22;
    scanf("%d%d%d%d", &x21, &y21, &x22, &y22);

    int arr[2001][2001] = {0};

    for(int i = x11 + OFFSET; i < x12 + OFFSET; i++) {
        for(int j = y11 + OFFSET; j < y12 + OFFSET; j++) {
            arr[i][j]++;
        }
    }

    for(int i = x21 + OFFSET; i < x22 + OFFSET; i++) {
        for(int j = y21 + OFFSET; j < y22 + OFFSET; j++) {
            arr[i][j]=0;
        }
    }

    int min_x = 2001;
    int min_y = 2001;
    int max_x = -1;
    int max_y = -1;
    int flag = 0;

    for(int a = 0; a < 2001; a++) {
        for(int b = 0; b < 2001; b++) {
            if(arr[a][b]==1) {
                flag = 1;
                if(a < min_x) min_x = a;
                if(a > max_x) max_x = a;
                if(b < min_y) min_y = b;
                if(b > max_y) max_y = b;
            }
        }
    }
    
    if(flag == 0) {
        printf("0");
    }
    else {
        int total = (max_x - min_x + 1) * (max_y - min_y + 1);
        printf("%d", total);
    }

    return 0;
}