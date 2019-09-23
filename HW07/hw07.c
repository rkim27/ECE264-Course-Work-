// ***
// *** You MUST modify this file.
// ***

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifdef TEST_COUNTINT
int countInt(char * filename)
{
  int count = 0;
  FILE * fle = fopen(filename, "r");
  if (fle == NULL)
    {
      return -1;
    }
  int num = 0;
  // count the number of integers in the file
  while (fscanf(fle,"%d", &num) != EOF)
    {
      count++;
    }
  // Please notice that if a file contains
  // 124 378 -56
  // There are three integers: 124, 378, -56
  // DO NOT count individual character '1', '2', '4' ...
  //
  // If fopen fails, return -1

  // remember to fclose if fopen succeeds
  fclose(fle);
  return count;
}
#endif

#ifdef TEST_READINT
bool readInt(char* filename, int * intArr, int size)
{
  FILE *fle = fopen(filename, "r");
  // if fopen fails, return false
  if (fle == NULL)
    {
      return false;
    }
  int num = 0;
  int count = 0;
  int i;
  for (i = 0; i < size; i++)
    {
      if (fscanf(fle, "%d", &num) != EOF)
	{
	  count++;
	  intArr[i] = num;
	}
      else
	{
	  break;
	}
    }

  if (count != size)
    {
      return false;
    }
  // read integers from the file.
  // 
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  fclose(fle);
  return true;
}
#endif

#ifdef TEST_COMPAREINT
int compareInt(const void *p1, const void *p2)
{
  // needed by qsort
  //
  // return an integer less than, equal to, or greater than zero if
  // the first argument is considered to be respectively less than,
  // equal to, or greater than the second.
  const int * ptr1 = (const int *) p1;
  const int * ptr2 = (const int *) p2;
  int val1 = *ptr1;
  int val2 = *ptr2;
  if (val1 < val2) {return -1;}
  if (val1 == val2) {return 0;}
  return 1;
}
#endif

#ifdef TEST_WRITEINT
bool writeInt(char* filename, int * intArr, int size)
{
  // if fopen fails, return false
  FILE *fle = fopen(filename, "w");
  if (fle == NULL)
    {
      return false;
    }
  int i;
  for (i = 0; i < size; i++)
    {
      fprintf(fle, "%d\n", intArr[i]);
    }
  // write integers to the file.
  // one integer per line
  // 
  // fclose and return true

  fclose(fle);
  return true;
}
#endif
