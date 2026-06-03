#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int N;
    int arr[200];
    memset(arr, 0, 200*sizeof(int));
    scanf("%d", &N);
    int x1, x2;
    for(int i = 0; i<N; i++) {
        scanf("%d%d", &x1, &x2);
        for(int j = x1+100; j<x2+100; j++) {
            arr[j]+= 1;
        }
    }
    int max = 0;
    for(int i = 0; i<200; i++) {
        if(max < arr[i]) max = arr[i];
    }
    printf("%d", max);
    return 0;
}