#include <stdio.h>

int arr[1000] = {0};

int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int cnt = 1;
    int max = 1;

    for(int j = 1; j < N; j++) {
        if(arr[j] > arr[j-1]) cnt++;
        else cnt = 1;

        if(max < cnt) max = cnt;
    }

    printf("%d", max);

    return 0;
}