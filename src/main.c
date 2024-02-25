#include <stdio.h>
#include <stdbool.h>

#include "webRequest.h"
#include "combinations.h"


int main(int argc, char *argv[])
{
 
  char base[] = "https://api.dictionaryapi.dev/api/v2/entries/en/";
  char url[100];

  if (argc == 2){
    strcpy(url, strcat(base, argv[1]));    
  } else if (argc > 2){
    printf("\033[33mToo many arguments supplied!\n");
  } else{
    printf("\033[33mAt least one argument expected.\n");
  } 

  char *result = request(url);

  checkExistance(result);

  free(result);

  printf("\033[0m");
  return 0;
}
