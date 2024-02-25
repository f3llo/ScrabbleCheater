#include <stdio.h>
#include <stdbool.h>

void checkExistance(char *requestAnswer)
{
  
  char nonExistent[] = "No Defenitions Found";

  if (strstr(requestAnswer, nonExistent) != NULL)
  {
    printf("\033[31mWord does not exist.\n");
  } else 
  {
    printf("\033[32mWord exists.\n");
  }
}

bool shouldSwap(char str[], int start, int curr)
{
    for (int i = start; i < curr; i++)
        if (str[i] == str[curr])
            return 0;
    return 1;
}

void findPermutations(char str[], int index, int n)
{
    FILE *fptr;
    fptr = fopen("combinations.txt", "w");

    if (index >= n) {
        printf("%s\n", str);
        
        fprintf(fptr, str);

        return;
    }
 
    for (int i = index; i < n; i++) {
 
        // Proceed further for str[i] only if it
        // doesn't match with any of the characters
        // after str[index]
        bool check = shouldSwap(str, index, i);
        if (check) {
            // Swapping the str[index] with str[i]
            char temp = str[index];
            str[index] = str[i];
            str[i] = temp;
            findPermutations(str, index + 1, n);
            // Swapping the str[index] with str[i]
            temp = str[index];
            str[index] = str[i];
            str[i] = temp;
        }
    fclose(fptr);
    }
}
//find all combinations
//recognize simple ones (local)
//command flag
//ncurses to display results
//discard impossible or short results flag
//understand webRequest better
