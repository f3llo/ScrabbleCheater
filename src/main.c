#include <stdio.h>

#include "webRequest.h"

int main(int argc, char **args)
{
 
  char base[] = "https://api.dictionaryapi.dev/api/v2/entries/en/";
  char url[100];

  strcpy(url, strcat(base, args[1]));
  request(url);
  printf("success!");
 
  return 0;
}
