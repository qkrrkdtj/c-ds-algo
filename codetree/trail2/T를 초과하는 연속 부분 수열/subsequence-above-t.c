#include <stdio.h>

int arr[1000] = {0};

int main() {
    // Please write your code here.
    int N, T;
    scanf("%d%d", &N, &T);

    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    int cnt = 0;
    int max = 0;

    for(int j = 0; j < N; j++) {
        if(T < arr[j]) cnt++;
        else cnt = 0;

        if(max < cnt) max = cnt;
    }

    printf("%d", max);
    
    return 0;
}