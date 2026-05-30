#include <stdio.h>
#include <string.h>

int main() {
    int m1, d1, m2, d2;
    char s[4];

    scanf("%d %d %d %d", &m1, &d1, &m2, &d2);
    scanf("%s", s);

    int days[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

    int td1 = d1;
    int td2 = d2;

    for(int i = 0; i < m1 - 1; i++)
        td1 += days[i];

    for(int i = 0; i < m2 - 1; i++)
        td2 += days[i];

    int target;

    if(strcmp(s, "Mon") == 0) target = 0;
    else if(strcmp(s, "Tue") == 0) target = 1;
    else if(strcmp(s, "Wed") == 0) target = 2;
    else if(strcmp(s, "Thu") == 0) target = 3;
    else if(strcmp(s, "Fri") == 0) target = 4;
    else if(strcmp(s, "Sat") == 0) target = 5;
    else target = 6;

    int cnt = 0;

    for(int i = 0; i <= td2 - td1; i++) {
        if(i % 7 == target)
            cnt++;
    }

    printf("%d", cnt);

    return 0;
}