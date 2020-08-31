#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#include "sys.h"
#include "stack.h"

#define Gamma 0xE2

struct Shell
{
	char text[256];
};

struct string
{
	char Char;
	char Str[256];
};

struct string str;

int main(void)
{
	int index = 0;
	struct Shell *shell = malloc(sizeof(struct Shell));
	bool exit = false;
	char* cmd = (char *)malloc(1024);
	char* input[5];
	char* path = (char *)malloc(1024);
	system("clear");
	printf("Welcome To Shell World!\n");
	printf("어서와!!\n");
	while(1)
	{
		//getcwd(path, 1024);
		path = myPath(); //파일 경로 확인
		printf("%s >> ", path);
		gets(shell->text);
		cmd = strtok(shell->text, " ");
		while(cmd != NULL)
		{
			input[index] = cmd;
			cmd = strtok(NULL, " ");
			index++;
		}
		if(strcmp(shell->text, "exit") == 0)
		{
			printf("Bye Bye\n");
			free(shell);
			free(path);
			return 0;
		}
		else
		{
			Command(input, shell->text);
		}
		index = 0;
		//printf("%s\n", shell->text);
	}
}