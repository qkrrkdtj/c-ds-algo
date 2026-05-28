#include <stdio.h>

int main() {
    // Please write your code here.
    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int m1, d1, m2, d2;
    scanf("%d%d%d%d", &m1, &d1, &m2, &d2);
    int td1 = d1;
    int td2 = d2;
    for(int i=0; i<m1-1; i++) {
        td1 += days[i];
    }
    for(int i=0; i<m2-1; i++) {
        td2 += days[i];
    }
    if(td1 < td2) {
        switch((td2-td1)%7) {
            case 0:
                printf("Mon");
                break;
            case 1:
                printf("Tue");
                break;
            case 2:
                printf("Wed");
                break;
            case 3:
                printf("Thu");
                break;
            case 4:
                printf("Fri");
                break;
            case 5:
                printf("Sat");
                break;
            case 6:
                printf("Sun");
                break;
        }
    }
    else {
        switch((td1-td2)%7) {
            case 0:
                printf("Mon");
                break;
            case 1:
                printf("Sun");
                break;
            case 2:
                printf("Sat");
                break;
            case 3:
                printf("Fri");
                break;
            case 4:
                printf("Thu");
                break;
            case 5:
                printf("Wed");
                break;
            case 6:
                printf("Tue");
                break;
        }
    }
        
    return 0;
}