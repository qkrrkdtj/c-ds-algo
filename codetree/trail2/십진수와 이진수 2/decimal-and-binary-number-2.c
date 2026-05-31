#include <stdio.h>
#include <string.h>

int main() {
    // Please write your code here.
    char s[11];
    scanf("%s", s);
    int num=0;
    int len = strlen(s);
    for(int i = 0; i<len; i++) {
        num = num*2 + (s[i] - '0');
    }
    num *= 17;
    int cnt = 0;
    int digit[20];
    while(num > 0) {
        digit[cnt++]=num%2;
        num/=2;
    }
    for(int i = cnt-1; i>=0; i--) {
        printf("%d", digit[i]);
    }
    return 0;
}