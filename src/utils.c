#include "utils.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void mysh_parse_command(const char* command,
                        int *argc, char*** argv)
{
	int count=0;
	char* str= (char*)malloc(sizeof(char));
	*argv=(char**)malloc(50*sizeof(char));
	**argv=(char*)malloc(50*sizeof(char));
	str=strcpy(str,command);
	str=strtok(str," \n\t");
	while(str!=NULL)
	{
			
		*((*argv)+count)=(char*)malloc(sizeof(char));
		strcpy(*((*argv)+count),str);
		count++;
		str=strtok(NULL," \n\t");
		*((*argv)+count)=(char*)malloc(sizeof(char));
	}
	
	if(count==0){
		strcpy(*((*argv)+count),"");
		count++;
	}
	*argc = count;
}

