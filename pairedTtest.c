/**                                                                                                                                                           
* Billy DeLucia                                                                                                                                               
* wld217                                                                                                                                                      
* CSE 411: Advanced Programming Techniques
* Assignment 1 Fall 2017
* 
* This program runs a paired T test with the sample data stored in the 
* pairedInput.txt file.                                                                                                                                                     
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
    printf("Usage: %s STR FILE\n", progname);
    printf("Print to STDOUT the lines of FILE that contain STR\n");
    printf("With no FILE, read standard input\n");
}

void runTest(int** sample, int n){
  int* dMean = diffs(sample, n);
  double mean_ = mean(dMean, n);
  double stdDev = standard_dev(dMean, mean_, n);
  double stdError = standardError(stdDev, n);

  double tVal = tStat(mean_, stdError); //t_value(mean_, n, expected, std);
  printf("Mean Difference: %f\nStandard Deviation %f\nStandard Error: %f\nT_Value: %f\n", mean_, stdDev, stdError, tVal);
}

/*
 * main() - The main routine parses arguments and dispatches to the
 *          task-specific code.
 */
int main(int argc, char **argv) {
  char* filename = "pairedInput.txt"; //"pairedInput.txt";
  int* lines = malloc(sizeof(int));
  char** contents = readFile(filename, lines);
  int** _sample = malloc(sizeof(int*) * *lines);
  
  printf("Input dataset:\n");
  for(int i = 0; i < *lines; i++){
    _sample[i] = malloc(sizeof(int) * 2);
    char* token = strtok(contents[i], ",");
    if(token != NULL){
      _sample[i][0] = atoi(token);
    }else{
      printf("Error\n No first value on line %i of %s\n", i + 1, filename);
      exit(0);
    }

    token = strtok(NULL, ",");
    if(token != NULL){
      _sample[i][1] = atoi(token);
    }else{
      printf("Error\n No second value on line %i of %s\n", i + 1 , filename);
      exit(0);
    }
    printf("%i, %i\n",  _sample[i][0], _sample[i][1]);
  }
  printf("\nResults: \n");
  //runTest(test, *lines, expected);
  runTest(_sample, *lines);

}
