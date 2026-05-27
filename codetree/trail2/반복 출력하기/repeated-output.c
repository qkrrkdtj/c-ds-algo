#include <stdio.h>
void print_string(void) {
    printf("12345^&*()_\n");
}
int main() {
    // Please write your code here.
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        print_string();
    }
    return 0;
}