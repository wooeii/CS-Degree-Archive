#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define FALSE 0
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

typedef struct ArrayStack //배열 스택 정의
{
	int top;
	char stack[100];
}ArrayStack;

int palindrome(char in_str[]) 
{
   ArrayStack s;
   int i;
   char ch, chs;
   int len = strlen(in_str);
	s.top = -1; // 스택을 초기화하라
   for ( i = 0 ; i < len ; i++ ) 
   {
		ch=in_str[i];
	// 만약 ch가 스페이스거나 구두점이면
 		if (ispunct(ch) || isspace(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		s.stack[++s.top]=ch; // 스택에 삽입한다.
	}
   for( i = 0 ; i < len ; i++ ) 
   {
		ch = in_str[i];
	// 만약 ch가 스페이스거나 구두점이면
		if (ispunct(ch) || isspace(ch)) continue;
		ch = tolower(ch); // ch를 소문자로 변경
		chs =s.stack[s.top--]; // 스택에서 문자를 꺼낸다
		if ( ch != chs ) return FALSE; // 실패
   }
   return TRUE; // 성공
}

int main()
{
	char input[30]={"madam, I'm Adam"};
	if(palindrome(input)==1)
	{
		printf("회문입니다.");
	}
	else if (palindrome(input)==0)
	{
		printf("회문이 아닙니다.");
	}
	return 0; 
}

