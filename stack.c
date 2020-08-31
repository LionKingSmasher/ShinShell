#include "stack.h"
#include <stdio.h>

int top = -1;

int IsEmpty()
{
	if(top<0) return 1;
	else return 0;
}

int IsFull()
{
	if(top >= Max_Stack_Size) return 1;
	else return 0;
}

void push(char value)
{
	if(IsFull()==1) printf("스택이 꽉 찼습니다!\n");
	else stack[++top] = value;
}

char pop()
{
	if(IsEmpty()==1) printf("비어있습니다!\n");
	else return stack[top--];
}