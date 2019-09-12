// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_ADDFILE
bool addFile(char * filename, int * sum)
{
  // You cannot assume * sum is zero. Thus, * sum needs to be set 0
  *sum = 0;
  // open a file whose name is filename for reading
  // if fopen fails, return false. Do NOT fclose
  FILE *fle = fopen(filename, "r");
  if (fle == NULL)
    {
      return false;
    }
  // if fopen succeeds, read integers using fscan (do not use fgetc)
  //
  int* num;   
  int i = 1;
  num = &i;

  while (fscanf(fle, "%d", num) != EOF)
    {
      *sum = *sum + *num;
    }
  //* sum stores the result of adding all numbers from the file
  // When no more numbers can be read, fclose, return true
  //
  fclose(fle);
  return true;
}
#endif


#ifdef TEST_WRITESUM
bool writeSum(char * filename, int sum)
{
  // open a file whose name is filename for writing
  FILE *fle = fopen(filename, "r");
   if (fle == NULL)
    {
      return false;
    }

   fprintf(fle, "%d\n", sum);
  // if fopen succeeds, write sum as an integer using fprintf
  // fprintf should use one newline '\n'
  // fclose, return true
  //

   fclose(fle);
  return true;
}
#endif
#endif
