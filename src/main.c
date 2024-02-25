#include <stdio.h>
#include <stdbool.h>

#include "webRequest.h"

bool checkExistance()
{
  
  FILE *fptr;
  fptr = fopen("request.json", "r");
  char contents[150];
  fgets(contents, 150, fptr);

  char nonExistent[] = "No Definitions Found";

  if (strstr(contents, nonExistent) != NULL)
  {
    return false;
  } else {
    return true;
  }

}

int main(int argc, char *argv[])
{
 
  char base[] = "https://api.dictionaryapi.dev/api/v2/entries/en/";
  char url[100];

  if (argc == 2)
  {
    strcpy(url, strcat(base, argv[1]));    
  }
  else if (argc > 2)
  {
    printf("\033[33mToo many arguments supplied!\n");
  }
  else 
  {
    printf("\033[33mAt least one argument expected.\n");
  }

  request(url);

  if (checkExistance() == false)
  {
    printf("\033[31mWord does not exist.\n");
  } else 
  {
    printf("\033[32mWord exists.\n");
  }
  
  printf("\033[0m");
  return 0;
}
