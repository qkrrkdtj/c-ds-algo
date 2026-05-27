# 스택 (Stack)

## 1. 정의

한쪽 끝에서만 데이터를 삽입하고 삭제할 수 있는 자료구조

- LIFO(Last In First Out) 구조
- 마지막에 들어간 데이터가 가장 먼저 나옴

---

## 2. 핵심 개념

### push
- 데이터 삽입

### pop
- 데이터 제거 및 반환

### peek
- 가장 위 데이터 확인

### top
- 가장 위 데이터를 가리키는 위치

---

## 3. 시간 복잡도

| 연산 | 시간복잡도 |
|---|---|
| push | O(1) |
| pop | O(1) |
| peek | O(1) |

---

## 4. 장점 / 단점

### 장점
- 구현이 단순함
- 삽입/삭제 빠름
- 재귀/DFS 구현에 적합

### 단점
- 중간 데이터 접근 불가
- LIFO 구조만 가능
- 크기 제한 가능(배열 구현 시)

---

## 5. 핵심 구현

### 초기화

```c
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top_idx = -1;
```

### isEmpty

```c
int isEmpty() {
    return top_idx == -1;
}
```

### isFull

```c
int isFull() {
    return top_idx >= MAX_SIZE - 1;
}
```

### push

```c
void push(int num) {
    if (isFull()) return;

    stack[++top_idx] = num;
}
```

### pop

```c
int pop(void) {
    if (isEmpty()) return -1;

    return stack[top_idx--];
}
```

### peek

```c
int peek(void) {
    if (isEmpty()) return -1;

    return stack[top_idx];
}
```

### size

```c
int size(void) {
    return top_idx + 1;
}
```

---

## 6. 자주 나오는 유형

### 괄호 검사
- 4949 균형잡힌 세상

### 문자열 뒤집기
- 역순 출력
- 문자열 Reverse

### 모노톤 스택
- 17298 오큰수
- 2493 탑

### DFS
- 재귀 호출
- 그래프 탐색

---

## 7. 실수 포인트

1. pop 전에 isEmpty 확인 안 함
2. push 전에 isFull 확인 안 함
3. top 인덱스 증감 위치 실수
4. 스택 오버플로우 발생
5. 빈 스택 접근 오류

---

## 8. 면접 핵심 질문

### 스택과 큐의 차이점

- 스택: LIFO
- 큐: FIFO

### 재귀 함수와 스택의 관계

함수 호출 정보가 시스템 스택에 저장됨

재귀 함수는 스택을 연속적으로 사용하는 구조

### 스택 오버플로우란?

스택 공간을 초과해서 메모리가 넘치는 현상

---

## 9. 정리

- LIFO 구조 자료구조
- push / pop 사용
- 삽입/삭제 O(1)
- DFS, 재귀, 괄호 문제에서 자주 사용
- top 관리 실수 주의