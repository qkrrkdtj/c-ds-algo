#include <stdio.h>
#include <string.h>

int main() {
    char binary[9];
    scanf("%s", binary);

    int num = 0;

    for(int i = 0; i < strlen(binary); i++) {
        num = num * 2 + (binary[i] - '0');
    }

    printf("%d\n", num);

    return 0;
}