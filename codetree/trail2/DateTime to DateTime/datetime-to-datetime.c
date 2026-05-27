#include <stdio.h>

int main() {
    // Please write your code here.
    int A, B, C;
    scanf("%d%d%d", &A, &B, &C);
    A = A-11;
    B = B-11;
    C = C-11;

    if (C<0) {
        C = C+60;
        B = B-1;
    }

    if(B<0) {
        B=B+24;
        A=A-1;
    }

    int time=0;
    if(A<0) {
        time = -1;
    }
    else {
        time = A*24*60 + B*60 + C;
    }

    printf("%d", time);
    return 0;
}