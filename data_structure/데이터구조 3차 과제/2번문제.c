#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define DataType char
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

typedef struct ArrayStack // 배열 스택 정의
{
	int top;
	DataType stack[MAX_SIZE];
} ArrayStack;

void init_stack(ArrayStack* AS) // 스택 초기화
{
	AS->top = -1;
}

int is_stack_full(ArrayStack* AS) // 스택이 포화상태인지 확인
{
	return AS->top == MAX_SIZE - 1;
}

int is_stack_empty(ArrayStack* AS) // 스택이 공백 상태인지 확인
{
	return AS->top == -1;
}

void push(ArrayStack* AS, DataType data) // 스택에 삽입
{
	if (is_stack_full(AS))
	{
		printf("포화 스택이므로 항목 삽입이 불가능합니다.\n");
		exit(1);
	}
	else
		AS->stack[++AS->top] = data;
}

DataType pop(ArrayStack* AS) // 스택에서 삭제
{
	if (is_stack_empty(AS))
	{
		printf("공백 스택이므로 항목 삭제가 불가능합니다.\n");
		exit(1);
	}
	else
		return AS->stack[AS->top--];
}

int comparison(char exp[]) //괄호가 맞는지 확인
{
	int i = 0;
	ArrayStack astack;
	init_stack(&astack);
	if(is_stack_full(&astack)) //스택이 꽉 찼을 경우  
	{
		return 0;
	}
	while (exp[i] != '\0') //괄호가 끝날 때까지 반복  
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') //괄호를 여는 경우  
		{
			push(&astack, exp[i]); //스택에 삽입  
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') //괄호를 닫는 경우 
		{
			if (is_stack_empty(&astack)) //스택이 비었는지 확인  
				return 0;
			else
			{
				DataType topElement = pop(&astack); //스택에서 꺼내서 topElement에 넣은 후 비교한다.  
				if ((exp[i] == ')' && topElement != '(') || (exp[i] == '}' && topElement != '{') ||(exp[i] == ']' && topElement != '['))
				{
					return 0;
				}
			}
		}
		i++;
	}
	if (is_stack_empty(&astack)) //스택이 비었을 경우  
	{
		return 1;		
	}
	else
	{
		return 0;	
	}
}

int main()
{
	char sentence[100]; // 괄호를 받는 문자
	scanf("%s", sentence); //문자열을 받는다.  
	if (comparison(sentence)) //괄호가 맞는지 확인 
	{
		printf("오류가 없습니다. \n");	
	}
	else
	{
		printf("오류가 있습니다. \n");
	}
	return 0;
}
