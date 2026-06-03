#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int N, K;
    scanf("%d%d", &N, &K);
    int arr[N];
    memset(arr, 0, N*sizeof(int));
    
    int A, B;

    for(int i = 0; i < K; i++) {
        scanf("%d%d", &A, &B);
        for(int j = A-1; j<B; j++) {
            arr[j]+=1;
        }
    }
    int max = 0;
    for(int i = 0; i<N; i++) {
        if(max<arr[i]) max = arr[i];
    }

    printf("%d", max);
    return 0;
}