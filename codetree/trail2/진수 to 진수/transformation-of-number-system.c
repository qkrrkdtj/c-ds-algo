#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    int A, B;
    char N[10];
    scanf("%d%d%s", &A, &B, N);
    int num = 0;
    int len = strlen(N);
    int digit[30];
    int cnt = 0;
    for(int i = 0; i<len; i++) {
        num = num*A + (N[i]-'0');
    }
    while(num > 0) {
        digit[cnt++] = num % B;
        num /= B;
    }
    for(int i = cnt - 1; i >= 0; i --) {
        printf("%d", digit[i]);
    }
    return 0;
}