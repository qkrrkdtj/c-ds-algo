#include <stdio.h>

int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);

    int num[1000];

    for(int i = 0; i < N; i++) {
        scanf("%d", &num[i]);
    }

    int cnt = 1;
    int max = 1;

    for(int j = 1; j < N; j++) {
        if(num[j] == num[j-1]) cnt++;
        else cnt = 1;

        if(max < cnt) max = cnt;
    }

    printf("%d", max);

    return 0;
}