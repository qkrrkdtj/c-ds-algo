#include <stdio.h>

int arr[1000];

int main() {
    int n, i;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Please write your code here.
 
    for(int j = 0; j < n; j++) {
        if(arr[j] > 0) arr[j] = 1;
        else if (arr[j] < 0) arr[j] = 0;
    }

    int cnt = 1;
    int max = 1;

    for(int k = 1; k < n; k++) {
        if(arr[k]==arr[k-1]) cnt++;
        else cnt = 1;

        if(max < cnt) max = cnt;
    }

    printf("%d", max);
    
    return 0;
}