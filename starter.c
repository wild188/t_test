#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "statistics.c"

/*
 * grep_file() - display all lines of filename that contain searchstr
 */
void grep_file(char *filename, char *searchstr) {
    /* TODO: Complete this function */
  FILE *file = fopen(filename, "r");
  if(!file){
    return;
  }

  char line[1024];
  while(fgets(line, 1024, file)){
    if(strstr(line, searchstr) != NULL){
      printf("%s", line);
    }
  }
  fclose(file);
}

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s STR FILE\n", progname);
    printf("Print to STDOUT the lines of FILE that contain STR\n");
    printf("With no FILE, read standard input\n");
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
  int sample[] = {11300, 9890, 10400, 9900, 10545, 12334};
  double mean_ = mean(sample, 6);
  double std = standard_dev(sample, mean_, 6);
  double tVal = t_value(mean_, 6, 10000, std);
  printf("Mean: %f\nStdev: %f\nT_Value: %f\n", mean_, std, tVal);
  
  
  /* for getopt */
    // long opt;

    // /* parse the command-line options.  For this program, we only support  */
    // /* the parameterless 'h' option, for getting help on program usage. */
    // while ((opt = getopt(argc, argv, "h")) != -1) {
    //     switch(opt) {
    //       case 'h': help(argv[0]); break;
    //     }
    // }

    // /* make sure we have two more parameters */
    // if (optind != argc - 2) {
    //     printf("Error: not enough arguments\n");
    //     exit(1);
    // }

    // /* TODO: fix this invocation */
    // grep_file(argv[1], argv[2]);
}
