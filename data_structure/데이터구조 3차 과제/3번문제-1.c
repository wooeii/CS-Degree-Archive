#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 100
#define MAX_LENGTH 100
#define DataType char
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

typedef struct ArrayQueue //배열 큐  
{
    int front;
    int rear;
    DataType queue[MAX_SIZE][MAX_LENGTH]; //2차원 배열을 사용하였다.  
} ArrayQueue;

void init_queue(ArrayQueue* AQ) //큐 초기화  
{
    AQ->front = AQ->rear = 0;
}

int is_queue_full(ArrayQueue* AQ) //큐가 포화 상태인지 확인  
{
    return ((AQ->rear + 1) % MAX_SIZE) == AQ->front;
}

int is_queue_empty(ArrayQueue* AQ) // 큐가 공백 상태인지 확인  
{
    return AQ->front == AQ->rear;
}

void enqueue(ArrayQueue* AQ, DataType* data) // 큐에 삽입  
{
    if (is_queue_full(AQ))
    {
        printf("포화 큐이므로 항목 삽입이 불가능합니다.\n");
        exit(1);
    }
    else
    {
        AQ->rear = (AQ->rear + 1) % MAX_SIZE;
        strncpy(AQ->queue[AQ->rear], data, MAX_LENGTH); //이름을 복사해서 큐에 넣음  
    }
}

DataType* dequeue(ArrayQueue* AQ) // 큐에서 삭제  
{
    if (is_queue_empty(AQ))
    {
        printf("공백 큐이므로 항목 삭제가 불가능합니다.\n");
        exit(1);
    }
    else
    {
        AQ->front = (AQ->front + 1) % MAX_SIZE;
        return AQ->queue[AQ->front];
    }
}

DataType* peek(ArrayQueue* AQ) //큐에서 front 데이터를 반환  
{
    if (is_queue_empty(AQ))
    {
        printf("공백 큐이므로 데이터가 없습니다.\n");
        exit(1);
    }
    else
    {
        return AQ->queue[(AQ->front + 1) % MAX_SIZE];
    }
}

int main()
{
    int input = 0; // 입력받을 학생의 수
    int i;
    char gender;    // 성별
    char name[MAX_LENGTH]; // 학생의 이름

    printf("미팅 주선 프로그램입니다.\n");
    ArrayQueue male;
    ArrayQueue female;
    init_queue(&male);
    init_queue(&female);

    printf("학생 수를 입력하세요: ");
    scanf("%d", &input);

    for (i = 0; i < input; i++) //학생수 input 만큼 반복  
    {
        printf("고객 이름: ");
        scanf("%s", name);
        printf("성별을 입력하세요 (f 또는 m): ");
        scanf(" %c", &gender);

        if (gender == 'f') //여자인경우  
        {
            enqueue(&female, name); //여자 큐에 넣는다.  
            if (!is_queue_empty(&female) && !is_queue_empty(&male)) //남자 큐와 여자 큐가 둘다 비어있지 않은 경우  
            {
                printf("커플이 탄생했습니다! 남자 %s과 여자 %s\n", peek(&male), peek(&female)); //출력  
                dequeue(&male); //제거  
                dequeue(&female);
            }
            else
            {
                printf("아직 대상자가 없습니다. 기다려주십시오.\n");
            }
        }
        else if (gender == 'm') //남자인 경우  
        {
            enqueue(&male, name);
            if (!is_queue_empty(&female) && !is_queue_empty(&male)) //남자 큐와 여자 큐가 둘다 비어있지 않은 경우  
            {
                printf("커플이 탄생했습니다! 남자 %s과 여자 %s\n", peek(&male), peek(&female)); //출력  
                dequeue(&male); //제거  
                dequeue(&female);
            }
            else
            {
                printf("아직 대상자가 없습니다. 기다려주십시오.\n");
            }
        }
    }

    return 0;
}
