#include <stdio.h>

int main() {
    // Please write your code here.
    char s[9];
    scanf("%s", s);
    int binary[8];
    for(int i = 0; i<8; i++) {
        binary[i]=s[i]-'0';
    }
    int num=0;
    for(int i = 0; binary[i]==0 || binary[i]==1; i++) {
        num = num * 2 + binary[i];
    }
    printf("%d", num);
    return 0;
}