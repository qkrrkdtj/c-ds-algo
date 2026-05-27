# 선형 큐 (Linear Queue)

## 1. 정의

한쪽에서는 데이터를 삽입하고 다른 한쪽에서는 데이터를 삭제하는 자료구조

- FIFO(First In First Out) 구조
- 먼저 들어온 데이터가 먼저 나감

---

## 2. 핵심 개념

### enqueue
- 데이터를 큐의 뒤(rear)에 삽입

### dequeue
- 데이터를 큐의 앞(front)에서 삭제

### front
- 삭제 위치를 가리킴

### rear
- 삽입 위치를 가리킴

---

## 3. 시간 복잡도

| 연산 | 시간복잡도 |
|---|---|
| enqueue | O(1) |
| dequeue | O(1) |
| peek | O(1) |

---

## 4. 장점 / 단점

### 장점
- 삽입/삭제 빠름
- FIFO 처리 가능
- 작업 순서 관리에 적합

### 단점
- 배열 기반은 크기 제한 존재
- front 증가로 인해 빈 공간 재사용 불가
- 공간 낭비 발생 가능

---

## 5. 핵심 구현

### 초기화

```c
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
```

### isEmpty

```c
int isEmpty() {
    return front == rear;
}
```

### isFull

```c
int isFull() {
    return rear >= MAX_SIZE - 1;
}
```

### enqueue

```c
void enqueue(int num) {
    if (isFull()) return;

    queue[++rear] = num;
}
```

### dequeue

```c
int dequeue(void) {
    if (isEmpty()) return -1;

    return queue[++front];
}
```

### peek

```c
int peek(void) {
    if (isEmpty()) return -1;

    return queue[front + 1];
}
```

### size

```c
int size(void) {
    return rear - front;
}
```

---

## 6. 자주 나오는 유형

### BFS
- 그래프 탐색
- 최단 거리 문제

### 작업 처리 시뮬레이션
- 프린터 큐
- 프로세스 스케줄링

### 카드 문제
- 2164 카드2

### 회전 큐
- 1021 회전하는 큐

---

## 7. 실수 포인트

1. dequeue 전에 isEmpty 확인 안 함
2. enqueue 전에 isFull 확인 안 함
3. front / rear 증가 위치 실수
4. 선형 큐 공간 낭비 문제
5. 배열 범위 초과

---

## 8. 면접 핵심 질문

### 큐와 스택의 차이점

- 큐: FIFO
- 스택: LIFO

### 선형 큐의 문제점은?

dequeue를 반복하면 앞 공간이 비어도 재사용 불가능

→ 공간 낭비 발생

### 이를 해결하는 방법은?

원형 큐(Circular Queue) 사용

### 큐가 사용되는 대표 사례는?

- BFS
- 운영체제 스케줄링
- 프린터 대기열
- 네트워크 패킷 처리

---

## 9. 정리

- FIFO 구조 자료구조
- enqueue / dequeue 사용
- 삽입/삭제 O(1)
- BFS와 시뮬레이션 문제에 자주 사용
- 선형 큐는 공간 낭비 문제 존재