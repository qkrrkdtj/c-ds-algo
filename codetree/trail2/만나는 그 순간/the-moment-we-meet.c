#include <stdio.h>

// 전역 변수로 선언하거나 크기를 충분히 넉넉하게 잡습니다.
// 최대 1000번씩 1000초 이동하므로 최대 시간은 1,000,000초입니다.
int A[1000005] = {0};
int B[1000005] = {0};

int main() {
    int N, M, t;
    char d;
    
    if (scanf("%d%d", &N, &M) != 2) return 0;

    // --- 1. A의 이동 기록 ---
    int cur = 0;
    int time_a = 0;
    for(int i = 0; i < N; i++) {
        scanf(" %c %d", &d, &t); // %c 앞에 공백을 넣어 엔터(개행문자)를 무시합니다.
        for(int j = 0; j < t; j++) {
            if(d == 'L') cur--;
            else if(d == 'R') cur++;

            A[++time_a] = cur;
        }
    }

    // --- 2. B의 이동 기록 ---
    cur = 0;      // B도 동일한 시작점에서 출발하므로 0으로 초기화!
    int time_b = 0; // B의 시간도 0부터 다시 시작!
    for(int a = 0; a < M; a++) {
        scanf(" %c %d", &d, &t); // %c 앞에 공백 추가
        for(int b = 0; b < t; b++) {
            if(d == 'L') cur--;
            else if(d == 'R') cur++;

            B[++time_b] = cur;
        }
    }

    // --- 3. 최초로 만나는 시간 찾기 ---
    // 문제 조건에서 A와 B가 총 이동한 시간은 항상 동일하다고 했습니다.
    int total_time = time_a; 
    int answer = -1; // 만나지 못했을 때의 기본값 -1

    for(int k = 1; k <= total_time; k++) {
        if(A[k] == B[k]) {
            answer = k; // 최초로 만난 시간을 저장하고
            break;      // 반복문을 빠져나옵니다.
        }
    }

    // 결과 출력
    printf("%d\n", answer);

    return 0;
}