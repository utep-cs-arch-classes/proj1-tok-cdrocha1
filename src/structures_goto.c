#include <stdio.h>

int main(){
  int rep = 5;
  char str[] = "Finished.";

 loop:
  printf("%d\n",rep);
  if(rep -- >= 0) goto loop;
  else goto end;

 end:
  printf("%s\n",str);




}
