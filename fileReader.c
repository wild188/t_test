#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "support.h"

extern char** readFile(char* filename, int* lines){
    FILE *file = fopen(filename, "r");
    int curChar;
  
    //if no file was input then we will print from stdin
    if(filename == NULL){
      file = stdin;
    }else if(!file){
      //error in filename
      perror("Filename  is not valid.\n");
      exit(0);
    }

    int lineCount = 0;
    char buffer[1024][1024];

    //if a file was given we will read each character and print it to stdout
    char line[1024];
    while(fgets(line, 1024, file)){
        //printf("%s", line);
        strcpy(buffer[lineCount], line);
        lineCount++;
    }

    *lines = lineCount;

    char** output = malloc(sizeof(char*) * lineCount);
    for(int i = 0; i < lineCount; i++){
        output[i] = malloc(sizeof(char) * strlen(buffer[i]));
        strcpy(output[i], buffer[i]);
    }

    fclose(file);
    return output;
}