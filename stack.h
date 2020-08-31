#pragma once

#define Max_Stack_Size 100

char stack[Max_Stack_Size];

extern int top;

int IsEmpty();
int IsFull();

void push(char value);
char pop();