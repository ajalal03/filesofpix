/**************************************************************
 *
 *     restoration.c
 *
 *     Assignment: HW1
 *     Authors:  Ryan Proulx, Adnan Jalal 
 *     Date:     2/3/22
 *
 *     This file holds the restoration functions that 
 *     help to un-corrupt the corrupted file we have been given.
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pnmrdr.h>
#include <string.h>
#include <stdbool.h>
#include <seq.h>
#include <table.h>
#include <atom.h>
#include <pnmrdr.h>
#include <except.h>



FILE *open_or_fail(char* filename);
void readFile(FILE *fp);
void splitLine(char **datapp, char **charOnly, char **numOnly, size_t length);
bool isNum(char c);
int findWidth(char *line);
size_t findMaxVal(Seq_T sequence);



int main(int argc, char *argv[])
{	
  
  Except_T exception = {""};
  
  if(argc > 2){
    RAISE(exception);
  }
  #endif
	if (argc == 1){
      //char* filename;
      char filename[100];
		  scanf("%s", filename);
      FILE *fp = open_or_fail(filename);
      
      readFile(fp);
      //FILE *fp = fopen(filename, "r");
      
      //char *data = "abcd";
      //datapp = &data;
      //char **datapp;
      //readaline(fp, datapp);
    //  printf("here");
      //fclose(fp);
	}
	else {
    
    FILE *fp = open_or_fail(argv[1]);
    readFile(fp);
			
      
    //  char **datapp;
      //char *data = "abcd";
      //datapp = &data;
    //  readaline(fp, datapp);
      
     //fclose(fp); 
	}
}

FILE *open_or_fail(char* filename){
  
  Except_T exception = {""};
  FILE *fp = fopen(filename, "r");
  
  if (fp == NULL){
    RAISE(exception);
  }
  return fp;
}



void readFile(FILE *fp){
    
    char* data = "";
    char **datapp;
    //int count = 0;
    
    //char **datapp;
     datapp = &data;
  
    
    // Table_T charTable = Table_new(500, NULL, NULL);
    // //Seq_T numSeq = Seq_new(0);
    // 
    // 
    // 
    // 
    // 
    // 
    // char* corrInfusion = "";
    
    while (feof(fp) == 0){
      
      // char *charOnly = malloc (1000 * sizeof(char));
      // char **charData;
      // charData = &charOnly;
      // 
      // char *numOnly = malloc (1000 * 2 * sizeof(char));
      // char **numData;
      // numData = &numOnly;
      
      //Seq_T currSeq = Seq_new(0);
      
      size_t size = readaline(fp, datapp);
      if(size == 0){
        break;
      }
      
      
      // splitLine(datapp,charData,numData, size);
      // free(*datapp);
      // //printf("%s\n", *numData);
      // 
      // //pointer to sequence  = table_get(table,key)
      // const char *key = Atom_string(*charData);
      // //make sequence first is numdata
      // char* numTemp = *numData;
      // //printf("numtemp is %p, numdata is %p", numTemp, *numData);
      // Seq_addhi(currSeq, numTemp);
      // 
      // if ((Table_get(charTable, key)) == NULL){
      //     //printf("The key %s is not in the table\n", key);
      //     Table_put(charTable, key, currSeq);
      //     Seq_free(&currSeq);
      // 
      // } 
      // else{
      //         Seq_T seqPtr = Table_get(charTable, key);
      //         Seq_addhi(seqPtr, numTemp);
      //         corrInfusion = *charData;
              //printf("Printing out first value %s\n", (char*)Seq_get(Table_get(charTable, key), 0));
                    
      }
      
      
    //   printf("key is %s", key);
    //  printf("the size of this seq is %i\n", Seq_length(Table_get(charTable,key)));
    //   printf("printing sequence to key... ");
    //   int len = Seq_length(Table_get(charTable, key));
    //   for(int i = 0; i < len; i++){
    //       printf("%s\n", (char*)Seq_get(Table_get(charTable, key), i));
    //   }
      //printf(*numData);
      //printf("\n");
      
      
    
      

    //find maxVal
    //send it to an export file 
    //display it
    
    // const char *corrInfAtom = Atom_string(corrInfusion);
    // Seq_T corrSeq = Table_get(charTable, corrInfAtom);
    // int height = Seq_length(corrSeq);
    // int width = findWidth(Seq_get(corrSeq, 0));
    // //printf("The correct infusion is %s", corrInfusion);
    // //printf("height is %i, width is %i\n", height, width);
    // //exit if size of line is over 1000
    // size_t maxValue = findMaxVal(corrSeq);
    // //printf("The maxval is %li\n", maxValue);
    // 
    // //FILE *correctPgm;
    // //correctPgm = fopen("correct.pgm", "w");
    // fprintf(stdout, "P5\n");
    // fprintf(stdout, "%i\n%i\n", width, height);
    // fprintf(stdout, "%li\n", maxValue);
    // for(int i = 0; i < width; i++){
    //     char* outputLine = Seq_get(corrSeq, i);
    //     for(int j = 0; j < (int) strlen(Seq_get(corrSeq, i)); j++){
    //         fprintf(stdout, "%c", outputLine[j]);
    //     }
    //     fprintf(stdout, "\n");
    // }
    // 
    // //Pnmrdr_T reader = Pnmrdr_new(correctPgm);
    // //Pnmrdr_mapdata mapData = Pnmrdr_data(reader);
    // 
    // //Seq_free(&numSeq);
    // Table_free(&charTable);  
    // free(*datapp);
    
      
}


void splitLine(char **datapp, char **charOnly, char **numOnly, size_t length){
    
    char space = ' ';
    
    size_t charOnlyIndex = 0;
    size_t numOnlyIndex = 0;
    //printf("Loop will run %i times \n", (int) length);
    
    for (size_t i = 0; i < length; i++){
        char character = (char) (*datapp)[i];
        if (isNum(character)){
          
            if ((isNum((char) (*datapp)[i+1]) && (char) (*datapp)[i+2] != '\n')
                || (isNum((char) (*datapp)[i+1]) && 
                (char) (*datapp)[i+2] == '\n')){
                (*numOnly)[numOnlyIndex] = character;
                numOnlyIndex++;
            }
            else {
              //printf("a space was added after %c\n", character);
              (*numOnly)[numOnlyIndex] = character;
              numOnlyIndex++;
              (*numOnly)[numOnlyIndex] = space;
              numOnlyIndex++;  
            }
        }
        else{
              (*charOnly)[charOnlyIndex] = character;
              charOnlyIndex++;
        }
    }
    // if(sizeof(numOnlyIndex == 0)){
    //   printf("numonly is 0\n");
    //   (*charOnly)[charOnlyIndex] = '\0';
    // }
    // else{
      (*charOnly)[charOnlyIndex] = '\0';
      (*numOnly)[numOnlyIndex] = '\0';
  //  }
}


bool isNum(char c){
    
    if (c == '0' || c == '1' || c == '2' 
    || c == '3' || c == '4' || c == '5'
    || c == '6' || c == '7' || c == '8' 
    || c == '9'){
        
        return true; 
        
    } 
    
    else{
        
        return false;
    }    
}

int findWidth(char *line){
  
    int length = strlen(line);
    int width = 0;
    
    for(int i = 0; i < length; i++){
      
        if((line)[i] == ' '){
            width++;
        }
      
    }  
    
    return width;
}


//does not work because the sequence will have 
//values of strings
size_t findMaxVal(Seq_T sequence){
    
    size_t maxVal = 0;
    int length = Seq_length(sequence);
    for (int i = 0; i < length; i++) {
        //printf("The line in the seq is %i\n", i);
        char *line = Seq_get(sequence, i);
        char *asciiLine = malloc(strlen(line));
        //printf("The size of the line is %li\n", strlen(line));
        int k = 0;
        for (size_t j = 0; j < strlen(line);) {
            
            //printf("k is %i\n", k);
            char numChar = line[j];
            char num2Char = line[j+1];
            char num3Char = line[j+2];
            if(numChar == '\0'){
              //printf("Break 1 was called\n");
              break;
            }
            int iNumChar = (int)numChar - '0';
            int iNum2Char = (int)num2Char - '0';
            int iNum3Char = (int)num3Char - '0';
            //printf("The 3 characters are %c,%c,%c\n", numChar, num2Char, num3Char);
            
            if(num2Char == ' '){
              //printf("iNumChar is %i\n", iNumChar);
              if((size_t) iNumChar > maxVal){
                  maxVal = iNumChar;
              }
            
              asciiLine[k] = (char) iNumChar;
              
              //printf("EACH CHAR FOR THE NUM %i IS %c\n",iNumChar,asciiLine[k]);
              //printf("potmaxval is %i\n", iNumChar);
              j+=2;
            }
            else if(num3Char == ' '){
                //printf("numchar is %i", (int)numChar);
                int potMaxVal = iNumChar * 10 + iNum2Char;
                //printf("potmaxval is %i\n", potMaxVal);
                if((size_t)potMaxVal > maxVal){
                    maxVal = (size_t)potMaxVal;
                }
                asciiLine[k] = (char) potMaxVal;
                j+=3;
            }
            else{
                //printf("this was hit");
              int potMaxVal = (iNumChar * 100) + 
                              (iNum2Char * 10) + iNum3Char;
              //printf("potmaxval is %i\n", potMaxVal);
              if((size_t)potMaxVal > maxVal){
                  maxVal = (size_t)potMaxVal;
              }
              asciiLine[k] = (char) potMaxVal;
              j+=4;
            }
            
            if(num2Char == '\0' || num3Char == '\0'){
              //printf("Break 2 was called\n");
              break;
            }
            k++;
          //printf("THE MAXVAL IS %li\n", maxVal);
        }
        asciiLine[k] = '\0';
        Seq_put(sequence, i, asciiLine);
    }
    
    return maxVal;
  
}


//display it
//exceptions
//over 1000 characters and need to exit
//free
