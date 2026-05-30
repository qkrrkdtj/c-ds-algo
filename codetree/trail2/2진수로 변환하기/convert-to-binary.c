#include <stdio.h>

int main() {
    // Please write your code here.
    int n;
    scanf("%d", &n);
    int digit[50000];
    int cnt=0;
    while(n>=2) {
        digit[cnt++] = n % 2;
        n /= 2;
    }
    digit[cnt++] = n;

    for(int i = cnt-1; i>=0; i--) {
        printf("%d", digit[i]);
    }
    return 0;
}