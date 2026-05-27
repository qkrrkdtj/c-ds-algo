#include <stdio.h>

int main() {
    // Please write your code here.
    int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1, m2, d1, d2;
    scanf("%d%d%d%d", &m1, &d1, &m2, &d2);
    int tm1=0;
    int tm2=0;
    for(int i=0; i<m1-1; i++) {
        tm1+=month[i];
    }
    for(int i=0; i<m2-1; i++) {
        tm2+=month[i];
    }

    int tt = tm2+d2 - (tm1+d1) + 1;
    printf("%d", tt);
    return 0;
}