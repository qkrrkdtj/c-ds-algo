# 이중 연결 리스트 (Doubly Linked List)

## 1. 정의

각 노드가 `prev`와 `next` 두 개의 포인터를 가지는 연결 리스트

- 양방향 탐색 가능
- head / tail로 앞뒤 접근 가능
- 단일 연결 리스트보다 메모리 사용량 증가

---

## 2. 핵심 개념

### Node 구조

```c
typedef struct Node {
    struct Node* prev;
    struct Node* next;
    int data;
} Node;
```

### prev / next

- prev : 이전 노드 저장
- next : 다음 노드 저장

### head / tail

- head : 시작 노드
- tail : 마지막 노드

---

## 3. 시간 복잡도

| 연산 | 시간복잡도 |
|---|---|
| 탐색 | O(n) |
| 삽입 | O(1) |
| 삭제 | O(1) |

※ 삽입/삭제 위치를 알고 있다는 가정

---

## 4. 장점 / 단점

### 장점
- 양방향 탐색 가능
- 앞뒤 삽입/삭제 O(1)
- 덱(Deque) 구현에 적합

### 단점
- prev 포인터 추가 메모리 필요
- 포인터 연결 실수 위험
- 구현 난이도 증가

---

## 5. 핵심 구현

### 초기화

```c
void init(void) {
    head = NULL;
    tail = NULL;
    size = 0;
}
```

### 정방향 출력

```c
void print_forward() {
    Node* current = head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
```

### 역방향 출력

```c
void print_backward() {
    Node* current = tail;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->prev;
    }
}
```

### 맨 앞 삽입

```c
void insert_first(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;

    if (tail == NULL) {
        tail = newNode;
    }

    size++;
}
```

### 맨 뒤 삽입

```c
void insert_last(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = tail;

    if (tail != NULL) {
        tail->next = newNode;
    }

    tail = newNode;

    if (head == NULL) {
        head = newNode;
    }

    size++;
}
```

### 삭제

```c
void delete_by_value(int value) {
    Node* current = head;

    while (current != NULL) {

        if (current->data == value) {

            if (current->prev != NULL) {
                current->prev->next = current->next;
            }
            else {
                head = current->next;
            }

            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            else {
                tail = current->prev;
            }

            free(current);
            size--;

            return;
        }

        current = current->next;
    }
}
```

---

## 6. 배열 기반 구현

```c
int dat[MAX];
int pre[MAX];
int nxt[MAX];
```

- 포인터 대신 배열 인덱스 사용
- 코딩 테스트에서 자주 사용
- 메모리 관리 단순

---

## 7. 자주 나오는 유형

- 덱(Deque) 구현
- 에디터 구현
- 요세푸스 문제
- 풍선 터뜨리기

대표 문제:
- 1406 에디터
- 1021 회전하는 큐
- 5430 AC

---

## 8. 실수 포인트

1. prev / next 연결 순서 실수
2. head / tail 갱신 누락
3. NULL 체크 안 함
4. 삭제 후 dangling pointer 발생

---

## 9. 면접 핵심 질문

### 단일 vs 이중 연결 리스트

- 단일: next만 존재
- 이중: prev + next 존재

### 삭제가 왜 O(1)인가?

prev / next 연결만 변경하면 되기 때문

### 언제 사용하는가?

- 양방향 탐색이 필요할 때
- 브라우저 뒤로가기
- 텍스트 에디터
- 덱 구현

---

## 10. 정리

- prev + next를 사용하는 연결 리스트
- 양방향 탐색 가능
- 앞뒤 삽입/삭제 O(1)
- 덱 구현에 자주 사용
- 포인터 연결 실수 주의