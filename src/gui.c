#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.c" 
int main(){
  char c;
  while((c = getchar()) != EOF){   //or != "\n"
    putchar(c);
  }
}
    
 
