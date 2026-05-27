# 연결 리스트 (Linked List)

## 1. 정의

노드(Node)들이 포인터로 연결되어 데이터를 저장하는 선형 자료구조

- 각 노드는 데이터와 다음 노드 주소를 저장
- 메모리가 연속적이지 않음
- 동적 크기 조절 가능

---

## 2. 왜 사용하는가?

배열의 단점을 해결하기 위해 사용

### 배열
- 중간 삽입/삭제 O(n)
- 크기 변경 어려움

### 연결 리스트
- 삽입/삭제 O(1)
- 동적 크기 조절 가능

→ 삽입/삭제가 많은 상황에서 유리

---

## 3. 핵심 개념

### Node
- 데이터 저장
- 다음 노드 주소 저장

```c
typedef struct Node {
    int data;
    struct Node* next;
} Node;
```

### Head
- 연결 리스트 시작 위치 저장

### Current
- 리스트 순회를 위한 포인터

```c
Node* current = head;
```

### 단일 vs 이중 연결 리스트

| 종류 | 특징 |
|---|---|
| 단일 연결 리스트 | next만 존재 |
| 이중 연결 리스트 | prev + next 존재 |

---

## 4. 시간 복잡도

| 연산 | 시간복잡도 |
|---|---|
| 탐색 | O(n) |
| 삽입 | O(1) |
| 삭제 | O(1) |

※ 삽입/삭제 위치를 알고 있다는 가정

---

## 5. 장점 / 단점

### 장점
- 삽입/삭제 빠름
- 동적 크기 조절 가능
- 메모리 낭비 적음

### 단점
- 탐색 느림 O(n)
- 추가 포인터 메모리 필요
- 캐시 효율 낮음
- 포인터 실수 위험

---

## 6. 핵심 구현

### 초기화

```c
void init(void) {
    head = NULL;
    l_list_size = 0;
}
```

### 탐색

```c
Node* search(int value) {
    Node* current = head;

    while (current != NULL) {
        if (current->data == value) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}
```

### 마지막 삽입

```c
void insert(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* current = search_last();
        current->next = newNode;
    }

    l_list_size++;
}
```

### index 삽입

```c
void insert_by_idx(int idx, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = value;
    newNode->next = NULL;

    if (idx == 0) {
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;

        for (int i = 0; i < idx - 1; i++) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    l_list_size++;
}
```

### 삭제

```c
void delete(int value) {
    Node* current = head;
    Node* pre = NULL;

    while (current != NULL) {
        if (current->data == value) {

            if (pre == NULL) {
                head = current->next;
            }
            else {
                pre->next = current->next;
            }

            free(current);
            l_list_size--;
            return;
        }

        pre = current;
        current = current->next;
    }
}
```

---

## 7. 자주 나오는 유형

- 연결 리스트 직접 구현
- Reverse Linked List
- slow / fast pointer
- 사이클 탐지
- 두 리스트 병합
- K번째 노드 삭제

---

## 8. 실수 포인트

1. free 안 해서 메모리 누수 발생
2. NULL 체크 안 함
3. head 변경 누락
4. next 접근 시 segmentation fault
5. 무한 루프 발생

---

## 9. 면접 핵심 질문

### 배열 vs 연결 리스트

- 배열: 접근 빠름 O(1)
- 연결 리스트: 삽입/삭제 빠름 O(1)

### 삽입이 왜 O(1)인가?

포인터만 변경하면 되기 때문

### 연결 리스트의 단점은?

- 랜덤 접근 불가
- 탐색 O(n)
- 메모리 사용량 증가

### 캐시 친화성이 낮은 이유는?

메모리가 연속적이지 않기 때문

---

## 10. 정리

- 포인터 기반 동적 자료구조
- 노드(Node) 단위로 연결
- 비연속 메모리 구조
- 탐색은 느리지만 삽입/삭제에 강함
- 포인터 실수 주의