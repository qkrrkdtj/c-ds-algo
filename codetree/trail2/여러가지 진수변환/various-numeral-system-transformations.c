#include <stdio.h>

int main() {
    // Please write your code here.
    int n, a;
    scanf("%d%d", &n, &a);
    int cnt = 0;
    int digit[100];
    while(n > 0) {
        digit[cnt++] = n % a;
        n /= a;
    }

    for(int i = cnt -1; i >= 0; i--) {
        printf("%d", digit[i]);
    }
    return 0;
}