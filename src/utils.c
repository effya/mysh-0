#include "utils.h"
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	//copy command to input
	char* input= (char*)malloc(sizeof(char));
	input= strcpy(input, command);

	//1D
	//*argc = (int*)malloc(sizeof(int));
	//2D
	*argv = (char**)malloc(sizeof(char));




	input=strtok(input, " ");	
	int i = 0;

	while(input!=NULL){

		int len = strlen(input);
		*argv=realloc(*argv, (i+1)*sizeof(char*));
		(*argv)[i]=malloc(len+1);

		strcpy((*argv)[i++], input);
		input = strtok(NULL, " ");
		
	}

	printf("argc == %d\n", i);
	printf("argv == {\"");
	for(int j = 0; j < i-1; ++j)
		printf("%s\",\"",(*argv)[j]);
	printf("%s\"}\n", (*argv)[i-1]);


	*argc = i;
}


