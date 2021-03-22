#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c == ' ' || c == '\t' || c == '\n'){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if (c == ' ' || c == '\t' || c == '\n'){
    return 0;
      }
  return 1;
}

char *word_start(char *str){
  int i = 0;
  char *ip = &str[1];
  while(str[i] != '\0'){
    if(str[i] == ' '){
      if(str[i+1] != '\0'){
	ip = &str[i+1];
	break;
      }
    }
    i++;
  }
  return ip;
}

char *word_end(char *str){
  int i = 0;
  char *ip = &str[0];
  while(str[i] != ' '){
    ip = &str[i+1];
    i++;
  }
  return ip;
}

int count_words(char *str){
  int count = 0;
  for(int i = 0; *(str+1)!= '\0'; i++){
    if(str[i] != ' ' && str[i+1] == ' '){
      count++;
    }
    if(str[i] != ' ' && str[i+1] == '\0'){   //accounts for the last word in the string
      count++;
    }
  }
  return count;
}



char *copy_str(char *inStr, short len){
  char *newString = (char *) malloc (len+1);
  char *ptr = newString;
  int i = 0;
  while(i<len){
    *(ptr) = *(inStr);
    ptr += 1;
    inStr+=1;
    i+=1;
  }
  *ptr = '\0';
  return newString;
}

char **tokenize(char* str){
  int numWords = count_words(str);
  char** finishedArray = (char**)malloc(numWords*sizeof(char*));
  char *temp = str;
  char *t = temp;
  int count = 0;
  while(*t != ' '){
    t++;
    count++;
  }
  finishedArray[0] = copy_str(temp,count);
  for(int i = 1; i<numWords; i++){
    temp = word_start(temp);
    char *t1 = temp;
    int countLen = 0;
    while(*t1 != ' '){
      t1++;
      countLen++;
    }
    finishedArray[i] = copy_str(temp,countLen);
    temp = word_end(temp);
  }
  finishedArray[numWords] = NULL;
  
  return finishedArray;
}

void print_tokens(char **tokens){
  while(*tokens != NULL){
    printf("%s\n",*tokens);
    tokens++;
  }
}

void free_tokens(char **tokens){
  free(tokens);
}
