#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);
    int arr[100];
    memset(arr, 0, 100*sizeof(int));
    int x1, x2;
    for(int i = 0; i < N; i++) {
        scanf("%d%d", &x1, &x2);
        for(int j=x1-1; j<x2; j++) {
            arr[j] += 1;
        }
    }

    int max=0;
    for(int i = 0; i<100; i++) {
        if(max<arr[i]) max = arr[i];
    }
    printf("%d", max);
    return 0;
}