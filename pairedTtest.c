#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "statistics.c"

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
  int n = 6;
  int expected = 10000;
  int temp[6][2] = {
    {11300, 11400},
    {9890, 9800}, 
    {10400, 11345}, 
    {9900, 9739}, 
    {10545, 10787}, 
    {12334, 12555}};
  int** sample = malloc(sizeof(int*) * n);
  for(int j = 0; j < n; j++){
    sample[j] = malloc(sizeof(int) * 2);
    sample[j] = temp[j];
    printf("%i, %i\n", sample[j][0], sample[j][1]);
  }

  int* dMean = diffs(sample, n);
  for(int i = 0; i < n; i++){
    printf("%i\n", dMean[i]);
  }
  double mean_ = mean(dMean, n);
  double std = standard_dev(dMean, mean_, n);
  double stdError = standardError(std, n);

  double tVal = tStat(mean_, stdError); //t_value(mean_, n, expected, std);
  printf("Mean: %f\nStandard Deviation %f\nStdError: %f\nT_Value: %f\n", mean_, std, stdError, tVal);
  
}
