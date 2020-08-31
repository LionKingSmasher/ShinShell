#include "calculator.h"
#include "sys.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct Cal_Command
{
	char input[256];
};
*/

void CalShell()
{
//	struct Cal_Command *command;
	char *cal_cmd = (char*)malloc(1024);
	char *input[5];
	printf("*************계산기 모드*************\n");
	int index = 0;
	while(1)
	{
		printf(">");
		gets(cal_cmd);
		if(strcmp(cal_cmd, "out")==0) break;
		else Cal(cal_cmd);
	}
	printf("*************************************\n");
}