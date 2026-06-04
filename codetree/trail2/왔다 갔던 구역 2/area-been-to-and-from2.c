#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int arr[20001];
    memset(arr, 0, 20001*sizeof(int));
    int zp = 10000;
    int N;
    scanf("%d", &N);
    int x;
    char dir;
    for(int i = 0; i<N; i++) {
        scanf("%d %c", &x, &dir);
        if(dir == 'R') {
            for(int i = zp; i<zp+x; i++) {
                arr[i]+=1;
            }
            zp +=x;
        } 
        else {
            for(int i = zp-1; i >= zp - x; i--) {
                arr[i] += 1;
            }
            zp-=x;
        }
    }
    int cnt = 0;
    for(int i = 0; i<20001; i++) {
        if(arr[i] >= 2) cnt++;
    }
    printf("%d", cnt);
    return 0;
}