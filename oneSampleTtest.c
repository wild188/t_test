
/**                                                                                                                                                           
* Billy DeLucia                                                                                                                                               
* wld217                                                                                                                                                      
* CSE 411: Advanced Programming Techniques
* Assignment 1 Fall 2017
* 
* This program runs a one sample T test with the sample data stored in the 
* oneSampleInput.txt file.                                                                                                                                                     
*/
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "statistics.c"
#include "fileReader.c"

/*
 * help() - Print a help message.
 */
void help(char *progname) {
    printf("Usage: %s EXPECTEDVALUE\n", progname);
    printf("Run one sample T test on data from the oneSampleInput.txt file and the expected value argument.\n");
}

void runTest(int* sample, int n, int expected){
  double mean_ = mean(sample, n);
  double std = standard_dev(sample, mean_, n);
  double tVal = t_value(mean_, n, expected, std);
  printf("Mean: %f\nStandard Deviation: %f\nT_Value: %f\n", mean_, std, tVal);
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
  int expected = 0;
  if(argc > 1){
    printf("Expected value: %s\n\n", argv[1]);
    expected = atoi(argv[1]);
  }else{
    help(argv[0]);
    exit(0);
  }

  char* filename = "oneSampleInput.txt";
  int* lines = malloc(sizeof(int));
  char** contents = readFile(filename, lines);
  int* test = malloc(sizeof(int) * *lines);
  
  printf("Input dataset:\n");
  for(int i = 0; i < *lines; i++){
    test[i] = atoi(contents[i]);
    printf("%i\n", test[i]);
  }
  printf("\n Results: \n");
  runTest(test, *lines, expected);
}
