#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> // 시간 측정을 위해서 필요한 라이브러리

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t)) // 두 변수의 값을 교환한다.
#define MAX_SIZE 100000 // 배열 크기

void quicksort_DC(int list[], int low, int high, int threshold);
int partition(int list[], int low, int high);
void insertion_sort(int list[], int low, int high);
void random(int list[], int size);

void quicksort_DC(int list[], int low, int high, int threshold) { //퀵정렬
    if (high - low + 1 <= threshold) { // 정렬할 크기가 임계값 이하인지 확인
        insertion_sort(list, low, high); // 삽입 정렬
    }
    else { // 정렬할 크기가 임계값보다 큰 경우
        int pivot_pos = partition(list, low, high); //분할
        quicksort_DC(list, low, pivot_pos - 1, threshold); // 왼쪽을 정렬
        quicksort_DC(list, pivot_pos + 1, high, threshold); // 오른쪽을 정렬
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

void insertion_sort(int list[], int low, int high) {//삽입정렬
    for (int i = low + 1; i <= high; i++) { // 두번째 원소부터 순서대로 처리
        int next = list[i]; //삽입할 값을 저장
        int j = i - 1; // 이전 원소를 비교하기 위해서 초기화
        while (j >= low && list[j] > next) { // 삽입 위치를 찾기 위해 반복
            list[j + 1] = list[j]; //한 칸씩 뒤로 이동
            j--;
        }
        list[j + 1] = next; // 삽입 위치에 값 저장
    }
}

void random(int list[], int size) { //랜덤값을 배열에 넣는다.
    for (int i = 0; i < size; i++) { 
        list[i] = rand() % MAX_SIZE; // 0부터 MAX_SIZE 사이 값을 랜덤 생성
    }
}

int main() {
    srand(time(NULL)); // 난수 초기화
    int list[MAX_SIZE]; //정렬할 배열
    int thresholds[] = {0,10,100,1000,10000}; //실험할 임계값들 설정
    int num_thresholds = sizeof(thresholds) / sizeof(thresholds[0]); // 임계값 개수 계산
    int num_trials = 100; // 평균 계산을 위해서 반복할 횟수

    for (int x = 0; x < num_thresholds; x++) { // 각 임계값에 대해 반복
        int threshold = thresholds[x]; //임계값 설정
        double total_time = 0.0; //시간 초기화
        for (int y = 0; y < num_trials; y++) { // 반복 횟수만큼 반복
            random(list, MAX_SIZE); //랜덤값 생성
            clock_t start = clock(); // 시간 측정 시작
            quicksort_DC(list, 0, MAX_SIZE - 1, threshold); //퀵정렬
            clock_t end = clock(); // 시간 측정 끝

            total_time += (double)(end - start) / CLOCKS_PER_SEC; //시간을 누적
        }
        printf("임계값: %d, 시간: %lf(s)\n", threshold, total_time / num_trials); // 평균 시간 출력
    }
    return 0;
}