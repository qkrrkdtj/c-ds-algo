# 원형 큐 (Circular Queue)

## 1. 정의

배열의 끝과 시작을 원형으로 연결하여 사용하는 큐 자료구조

- FIFO(First In First Out) 구조
- 선형 큐의 공간 낭비 문제 해결
- front / rear가 순환하며 이동

---

## 2. 핵심 개념

### enqueue
- rear 위치에 데이터 삽입

### dequeue
- front 위치에서 데이터 삭제

### modulo 연산
- 배열 끝에 도달하면 다시 처음으로 이동

```c
(index + 1) % MAX_SIZE
```

### 공백 한 칸 사용

원형 큐는 보통 front == rear 를 공백 상태로 사용하기 때문에  
가득 찬 상태와 구분하기 위해 한 칸을 비워둠

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
- 선형 큐 공간 낭비 해결
- 삽입/삭제 빠름
- 배열 공간 재사용 가능

### 단점
- modulo 연산 필요
- 구현 난이도 증가
- full / empty 구분 주의

---

## 5. 핵심 구현

### 초기화

```c
#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = 0;
int rear = 0;
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
    return (rear + 1) % MAX_SIZE == front;
}
```

### enqueue

```c
void enqueue(int num) {
    if (isFull()) return;

    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = num;
}
```

### dequeue

```c
int dequeue(void) {
    if (isEmpty()) return -1;

    front = (front + 1) % MAX_SIZE;
    return queue[front];
}
```

### peek

```c
int peek(void) {
    if (isEmpty()) return -1;

    return queue[(front + 1) % MAX_SIZE];
}
```

### size

```c
int size(void) {
    return (rear - front + MAX_SIZE) % MAX_SIZE;
}
```

---

## 6. 자주 나오는 유형

### 버퍼 구현
- 키보드 입력 버퍼
- 네트워크 버퍼

### 운영체제 스케줄링
- Round Robin

### 회전 큐 문제
- 1021 회전하는 큐

### BFS
- 큐 최적화 구현

---

## 7. 실수 포인트

1. front / rear modulo 연산 누락
2. full / empty 조건 혼동
3. 배열 한 칸 비워두는 규칙 잊음
4. dequeue 전에 isEmpty 확인 안 함
5. enqueue 전에 isFull 확인 안 함

---

## 8. 면접 핵심 질문

### 선형 큐의 문제점은?

앞 공간을 재사용하지 못해 공간 낭비 발생

### 원형 큐는 어떻게 해결하는가?

배열 끝과 시작을 연결하여 빈 공간 재사용

### 왜 한 칸을 비워두는가?

front == rear 를 공백 상태로 사용하기 때문

### 원형 큐가 사용되는 곳은?

- 버퍼
- 운영체제 스케줄링
- 네트워크 처리
- 스트리밍 시스템

---

## 9. 정리

- 선형 큐의 공간 낭비 문제 해결
- 배열을 원형으로 사용
- FIFO 구조
- enqueue / dequeue O(1)
- modulo 연산과 full 조건 주의