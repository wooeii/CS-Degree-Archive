#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) // x와 y의 값을 t를 이용해 교환
#define MAX_SIZE 100000// 배열의 크기

void merge_sort_DC(int list[], int low, int high);
void merge(int list[], int low, int mid, int high);
void quicksort_DC(int list[], int low, int high);
int partition(int list[], int low, int high);

void merge_sort_DC(int list[], int low, int high) { // 합병정렬
    int middle;
    if (low < high) { //부문제 크기가 2 이상
        middle = (low + high) / 2; // 중간 지점을 계산
        merge_sort_DC(list, low, middle); // 중간을 기준으로 왼쪽 정렬
        merge_sort_DC(list, middle + 1, high); // 중간을 기준으로 오른쪽 정렬
        merge(list, low, middle, high); //합치기
    }
}


void merge(int list[], int low, int mid, int high) { //배열 합치기
    int n1 = mid - low + 1; // 왼쪽 배열의 크기
    int n2 = high - mid; // 오른쪽 배열의 크기
    int* sorted = (int*)malloc((n1 + n2) * sizeof(int)); //동적메모리
    int i = low, j = mid + 1, s = 0;

    while (i <= mid && j <= high) { //병합
        if (list[i] <= list[j]) { 
            sorted[s++] = list[i++]; // 왼쪽 배열이 더 작으면 왼쪽 배열 값을 삽입
        }
        else { 
            sorted[s++] = list[j++]; // 오른쪽 배열이 더 작으면 오른쪽 배열 값을 삽입
        }
    }
    while (i <= mid) sorted[s++] = list[i++];  // 왼쪽 배열에 남은 값들 처리
    while (j <= high) sorted[s++] = list[j++]; // 오른쪽 배열에 남은 값들 처리

    for (int k = 0; k < (n1 + n2); k++) {  // 합쳐진 배열을 원본 배열에 복사
        list[low + k] = sorted[k];
    }
    free(sorted);  // 동적 메모리 해제
}


void quicksort_DC(int list[], int low, int high) { // 퀵정렬
    int pivot_pos;
    if (low < high) { // 데이터가 하나 남을때까지 
        pivot_pos = partition(list, low, high); // 분할
        quicksort_DC(list, low, pivot_pos - 1); // 왼쪽을 정렬
        quicksort_DC(list, pivot_pos + 1, high); // 오른쪽을 정렬
    }
}


int partition(int list[], int low, int high) { //분할
    int pivot = list[low], i = low + 1, j = high, temp;

    while (i <= j) {
        while (i <= high && list[i] <= pivot) i++; // 피봇보다 작은 값 찾기
        while (j > low && list[j] > pivot) j--; // 피봇보다 큰 값 찾기

        if (i < j) {
            SWAP(list[i], list[j], temp); // i<j일경우 값을 교환
        }
    }
    SWAP(list[low], list[j], temp); // 피봇과 j 값을 교환하여 피봇을 올바른 위치로 보냄
    return j; // 반환
}

void random(int list[], int size) { //랜덤값을 배열에 넣음
    for (int i = 0; i < size; i++) {
        list[i] = rand() % 1000000; // 0부터 1000000사이 값을 랜덤으로 배열에 넣음
    }
}

int main() {
    srand(time(NULL)); //난수 초기화

    int n = MAX_SIZE; // 배열의 크기
    int list[MAX_SIZE], list_copy[MAX_SIZE]; // 원본 배열과 정렬할 배열
    for (int i = 0; i < 10; i++)
    {
        random(list, n); // 배열에 랜덤값 넣기

        for (int i = 0; i < n; i++) list_copy[i] = list[i]; // 정렬할 배열에 원본 배열값 넣기
        printf("-----<정렬할 크기: %d>-----\n", n);
        clock_t start = clock(); //시간 측정 시작
        merge_sort_DC(list_copy, 0, n - 1); // 합병정렬
        clock_t end = clock(); //시간 측정 끝
        printf("합병정렬 소요 시간: %lf\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 출력

        for (int i = 0; i < n; i++) list_copy[i] = list[i]; // 정렬할 배열에 원본 배열값 넣기
        start = clock(); //시간 측정 시작
        quicksort_DC(list_copy, 0, n - 1); // 퀵정렬
        end = clock(); //시간 측정 끝
        printf("  퀵정렬 소요 시간: %lf\n\n", (double)(end - start) / CLOCKS_PER_SEC); //시간 출력

    }

    return 0; // 프로그램 종료
}