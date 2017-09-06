/**                                                                                                                                                           
* Billy DeLucia                                                                                                                                               
* wld217                                                                                                                                                      
* CSE 411: Advanced Programming Techniques
* Assignment 1 Fall 2017
* 
* Provides a standard file reader function.                                                                                                                                                    
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char** readFile(char* filename, int* lines){
    FILE *file = fopen(filename, "r");
    int curChar;
  
    //if no file was input then we will print from stdin
    if(filename == NULL){
        perror("No filename given");
    }else if(!file){
      //error in filename
      printf("Filename %s is not valid.\n", filename);
      perror("Filename not valid.\n");
      exit(0);
    }

    int lineCount = 0;
    char buffer[1024][1024];

    //if a file was given we will read each character and print it to stdout
    char line[1024];
    while(fgets(line, 1024, file)){
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