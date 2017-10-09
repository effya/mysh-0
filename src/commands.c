#include <string.h>
#include "commands.h"
#include <unistd.h>
#include <stdio.h> 
int do_cd(int argc, char** argv) {

  if (!validate_cd_argv(argc, argv))
    return -1;

  char *cwd;
  char wd[BUFSIZ];
  cwd = getcwd(NULL, BUFSIZ);

//relative path

if(argc == 1){
	chdir("home/");
	printf("%s", cwd);

}

else{

  if(argv[1] != "/"){
	if(argv[1] == ".."){
		chdir("..");
		printf("%s", cwd);
	}
	else if((argv[1] == "."))
		printf("%s", cwd);
	else;
  }

//absolute path
  else{
	chdir("/(*argv)[1]");	
	printf("%s", cwd);
	}
}

  return 0;
}


int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  else{
    char *cwd;
    char wd[BUFSIZ];

    cwd = getcwd(NULL, BUFSIZ);
    printf("%s\n",cwd);
    return 0;
  }
}

int validate_cd_argv(int argc, char** argv) {
  
 if(argc > 0)
	return 1;
}

int validate_pwd_argv(int argc, char** argv) {
  if(argc == 1)
 	 return 1;
}

