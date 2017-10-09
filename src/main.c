
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands.h"
#include "utils.h"

static void release_argv(int argc, char** argv);

int main()
{
  char buf[8096];
  int argc;
  char** argv;

  while (1) {
    fgets(buf, 8096, stdin); // get string from buf

    mysh_parse_command(buf, &argc, &argv);
// deliver buf, &int &**argv , parsing result == in argv
// finally, argv is point an 2d array that sets of parsed string


   //strcmp
  // abc abcd  -> -1, abcd abc -> 1, abc abc ->0
    if (strcmp(buf, "") == 0) {
      goto release_and_continue; // buf empty
    }

    else if (strcmp(argv[0], "cd") == 0) { // argv[0], parsed first token == cd

      if (do_cd(argc, argv)) {
        fprintf(stderr, "cd: Invalid arguments\n");
      }
     //do_cd == 0 

    }

    else if (strcmp(argv[0], "pwd") == 0) {

      if (do_pwd(argc, argv)) {
        fprintf(stderr, "pwd: Invalid arguments\n");
      }
    }
   
    else if (strcmp(argv[0], "exit") == 0) {
      goto release_and_continue;
    }

    else {
      fprintf(stderr, "%s: command not found\n", argv[0]);
    }


release_and_continue:
    release_argv(argc, argv);
    continue;

release_and_exit:
    release_argv(argc, argv);
    break;
 }

  return 0;
}

static void release_argv(int argc, char** argv) {
  for (int i = 0; i < argc; ++i) {
    free(argv[i]);
  }
  free(argv);
}


