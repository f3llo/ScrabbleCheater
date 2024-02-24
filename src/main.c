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

  strcpy(url, strcat(base, argv[1]));

  request(url);

  if (checkExistance() == false)
  {
    printf("Word does not exist.\n");
  } else 
  {
    printf("Word exists.\n");
  }
 
  return 0;
}
