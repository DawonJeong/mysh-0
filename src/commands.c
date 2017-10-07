#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "commands.h"
#include "utils.h"

int do_cd(int argc, char** argv) {
	
	if (validate_cd_argv(argc, argv)!=1)
		return -1;

	

	char path[256] =" ";
//	if(argc==1){
//		strcpy(path,argv[0]);
//		chdir(getenv("HOME"));
//	}
//	else{
		strcpy(path,argv[1]);
		if(strcmp(path,"~")==0)
			chdir(getenv("HOME"));
		else
			chdir(path);
	//}
		
	return 0;
		
}

int do_pwd(int argc, char** argv) {
	if (validate_pwd_argv(argc, argv)!=1)
		return -1;

	char cwd[1024];
	if(getcwd(cwd,sizeof(cwd))!=NULL)
		printf("Current working dir : %s\n",cwd);


 	 return 0;
}

int validate_cd_argv(int argc, char** argv) {

	if(argc==2){
		if(strcmp(argv[0],"cd")!=0)
			return 0;
		else
			return 1;
	}
	else
		return 0;
}

int validate_pwd_argv(int argc, char** argv) {
 	if(argc==1){
		if(strcmp(argv[0],"pwd")!=0)
			return 0;
		else
			return 1;
	}
	else
  		return 0;
}


