#include <math.h>

#ifndef SUPPORT_H__
#define SUPPORT_H__



/*
 * Store information about the student who completed the assignment, to
 * simplify the grading process.  This is just a declaration.  The definition
 * is in student.c.
 */
extern struct student_t {
  char *name;
  char *email;
} student;

/*
 * This function verifies that the student name is filled out
 */
extern int difference_1(int x, int y){
    return x - y;
}

extern double mean(int* sample, int len){
    //int n = sample.length;
    int total = 0;
    for(int i = 0; i < len; i++){
        total += sample[i];
    }
    double mean = total / (double)len;
    return mean;
}

extern double standard_dev(int* sample, double mean, int len){
    double variance;
    int totalDiff2rd = 0;
    for(int i = 0; i < len; i++){
        double diff = sample[i] - mean;
        totalDiff2rd += diff * diff;

    }
    variance = totalDiff2rd / (double)(len -1);

    return sqrt(variance);
}

extern double t_value(int mean, int n, int expected, int stdev){
    int diff = abs(mean - expected);
    double tValue = diff / (stdev / (double)sqrt(n));
    return tValue;
}

#endif
