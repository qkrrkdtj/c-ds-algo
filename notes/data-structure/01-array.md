# 배열 (Array)

## 1. 정의

같은 자료형의 데이터를 연속된 메모리 공간에 저장하는 선형 자료구조

- 인덱스를 통한 O(1) 접근 가능
- 메모리에 연속 저장
- 가장 기본적인 자료구조

---

## 2. 핵심 개념

### 인덱스(Index)
- 0부터 시작
- `arr[i]` 형태로 접근
- 랜덤 접근(Random Access) 가능

### 연속 메모리
- 메모리가 붙어있음
- 캐시 효율이 좋음
- 주소 계산 가능

### 고정 크기
- 선언 시 크기 결정
- 중간 크기 변경 불가 (정적 배열)

---

## 3. 시간 복잡도

| 연산 | 시간복잡도 |
|---|---|
| 접근 | O(1) |
| 탐색 | O(n) |
| 끝 삽입 | O(1) |
| 중간 삽입 | O(n) |
| 중간 삭제 | O(n) |

---

## 4. 장점 / 단점

### 장점
- 빠른 인덱스 접근
- 구조가 단순함
- 캐시 친화적
- 구현이 쉬움

### 단점
- 중간 삽입/삭제 비효율적
- 크기 고정
- 인덱스 에러 발생 가능

---

## 5. 핵심 구현

### 초기화

```c
void init(ArrayList* list) {
    list->size = 0;
}
```

### 탐색

```c
int search(ArrayList* list, int value) {
    for (int i = 0; i < list->size; i++) {
        if (list->arr[i] == value) {
            return i;
        }
    }
    return -1;
}
```

### 마지막 삽입

```c
void insert_last(ArrayList* list, int value) {
    list->arr[list->size] = value;
    list->size++;
}
```

### index 삽입

```c
void insert(ArrayList* list, int index, int value) {
    for (int i = list->size; i > index; i--) {
        list->arr[i] = list->arr[i - 1];
    }

    list->arr[index] = value;
    list->size++;
}
```

### index 삭제

```c
void delete_by_index(ArrayList* list, int index) {
    for (int i = index; i < list->size - 1; i++) {
        list->arr[i] = list->arr[i + 1];
    }

    list->size--;
}
```

---

## 6. 자주 나오는 알고리즘 유형

- 투 포인터
- 슬라이딩 윈도우
- 누적합
- 이분 탐색
- 카운팅 배열

---

## 7. 실수 포인트

1. 인덱스 범위 초과
2. 배열 크기 부족
3. 정렬 안 했는데 이분 탐색 사용
4. 0-index / 1-index 혼동
5. 오버플로우

---

## 8. 면접 핵심 질문

### 배열의 접근이 왜 O(1)인가?
주소 계산으로 바로 접근 가능하기 때문

### 배열이 캐시 친화적인 이유는?
연속 메모리 구조이기 때문

### 배열 vs 연결 리스트
- 배열: 접근 O(1)
- 연결 리스트: 삽입/삭제 유리

---

## 9. 정리

- 가장 기본적인 자료구조
- 인덱스 기반 O(1) 접근
- 연속 메모리 구조
- 삽입/삭제는 느림