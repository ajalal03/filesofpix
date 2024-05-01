#include <stdio.h>
#include <stdlib.h>
#include <pnmrdr.h>
#include "limits.h"



size_t readaline(FILE *inputfd, char **datapp){
  
    
    if(inputfd == NULL || datapp == NULL){
        //return checked runtime error??
        exit(0);
    }
    
    char *line;
    
    int size = 1000;
    line = (char *)malloc(sizeof(char) * size);
    char* temp = line;
    //printf("here\n");
    int numBytes = 0;
    fgets(line, INT_MAX, inputfd);
    strlen(line);
    //memExpand(&line,&numBytes);
    //printf("also\n");
    //is not getting the first character
    //printf("line is %s ...", line);
    *datapp = line;
    
  //  printf("after line\n");
    if (*datapp == NULL) {
        free(temp);
        return 0;
    }
    //printf("after line 1\n");
    
    //printf("after numBytes");
    while(*line++){
      numBytes++;
      if (numBytes >= size - 2){
          size = size *2;
          temp = (char*) malloc(sizeof(char) * size);
          memcpy(temp,line,strlen(line) *sizeof(char));
          free(line);
          line = temp;
      }
      
    }
    (*datapp)[numBytes] = '\0';
    //(line)[numBytes] = '\0';
    //printf("after *line");
    //free(line);
    
    //need to make sure to return numBytes 
    //does this include the \n at the end?
    return numBytes;
   
}













