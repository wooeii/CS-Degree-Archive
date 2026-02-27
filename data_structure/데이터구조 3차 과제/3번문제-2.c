#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType char
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

typedef struct Qnode 
{
    DataType data[100];
    struct Qnode *link;
} Qnode;
typedef struct LinkedQueue //큐의 헤드 노드 구조 정의  
{
	Qnode *front; //헤드 포인터 겸용  
	Qnode *rear;
}LinkedQueue;

void init_queue(LinkedQueue* LQ) //큐 초기화  
{
	LQ->front=LQ->rear=NULL;
}

int is_queue_full(Qnode *node) // 큐가 포화상태인지 확인  
{
	return node ==NULL;
}

int is_queue_empty(LinkedQueue *LQ) //큐가 공백 상태인지 확인  
{
	return LQ->front ==NULL;
}

void enqueue(LinkedQueue *LQ, DataType* data) //큐에 삽입  
{
	Qnode *new = (Qnode *)malloc(sizeof(Qnode));
	if(is_queue_full(new))
	{
		printf("포화 큐이므로 항목 삽입이 불가능합니다.\n");
		exit(1);
	}
	else {
		strcpy(new->data, data); //입력받은 이름을 복사하여 연결리스트에 저장  
		new->link = NULL;
		if(is_queue_empty(LQ))LQ->front=new;
		else LQ->rear->link=new;
		LQ->rear=new;
	}
}

DataType dequeue(LinkedQueue *LQ) //큐에서 삭제  
{
	if(is_queue_empty(LQ))
	{
		printf("공백 큐이므로 항목 삭제가 불가능합니다.\n");
		exit(1);
	}
    else
    {
        Qnode *deleted = LQ->front;
        LQ->front = LQ->front->link;
        if (is_queue_empty(LQ))
            LQ->rear = NULL;
        free(deleted);
    }
}

DataType* peek(LinkedQueue *LQ) //큐에서 front 데이터를 반환  
{
	if(is_queue_empty(LQ))
	{
		printf("공백 큐이므로 데이터가 없습니다.\n");
		exit(1);
	}
	else return LQ->front->data;
}

int main()
{
    int input = 0; // 입력받을 학생의 수
    int i;
    char gender;    // 성별
    char name[100]; // 학생의 이름

    printf("미팅 주선 프로그램입니다.\n");
    LinkedQueue male;
    LinkedQueue female;
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
                printf("커플이 탄생했습니다! 남자 %s과 여자 %s\n", peek(&male), peek(&female));  //출력  
                dequeue(&male);//제거 
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
