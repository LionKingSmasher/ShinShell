#include "sys.h"
#include "stack.h"
#include "crypt.h"
#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

struct NUM
{
//	char first_char;
//	char second_char;
	int first_num;
	int second_num;
	char first_str[2];
	char secod_str[2];
};

struct RESULT
{
	int num;
	char str[2];
};

struct NUM Num;
struct RESULT result;

char* myPath()
{
	char *path;
	path = (char *)malloc(1024);
	getcwd(path, 1024);
	return path;
}

void Command(char* command[], char* command_2)
{
	if(strcmp(command[0], "information")==0) Information();
	else if(strcmp(command[0], "cd")==0) CD(command[1]);
	else if(strcmp(command[0], "calculator")==0) CalShell();
	else if(strcmp(command[0], "ls")==0) system("ls");
	else error_message(command[0]);
}

void Cal(char* input)
{
	char str[2] = "";
	//////////////////////수, 기호 탐색 구역//////////////////////
	for(int j = 0; j < strlen(input); j++) //기호 탐색 구역
	{
		sprintf(str, "%c", input[j]);
		if(atoi(str)==NULL) push(input[j]);
		//else continue;
	}
	for(int i = 0; i < strlen(input); i++) //수 탐색 구역
	{
		if(input[i]!='+') push(input[i]);
	}
	//////////////////////////////////////////////////////////

	///////////////////////////계산 부분////////////////////////
	for(int i = 0; i < strlen(input); i++)
	{
		if(input[i]=='+')
		{
			sprintf(Num.first_str, "%c", pop());
			sprintf(Num.secod_str, "%c", pop());
			Num.first_num = atoi(Num.first_str);
			Num.second_num = atoi(Num.secod_str);
			switch(input[i])
			{
			case '+':
				result.num = Num.first_num + Num.second_num;
				sprintf(result.str, "%d", result.num);
				push(result.str[0]);
				break;
			default:
				break;
			}
		}
	}
	printf("%d\n", result.num);
	//////////////////////////////////////////////////////////
}

void Information()
{
	printf("************************정보************************\n");
	printf("프로그램명: ShinShell(임시명칭)\n");
	printf("버전: v20200826b\n");
	printf("개발자: TigerShin(신현규)\n");
	printf("개발 언어: C\n");
	printf("***************************************************\n");
}

void CD(char* dir)
{
	chdir(dir);
}

void error_message(char* message)
{
	printf("%s라는 명령어가 존재하지 않습니다!\n", message);
}