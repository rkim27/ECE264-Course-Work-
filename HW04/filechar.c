// ***
// *** You MUST modify this file, only the ssort function
// ***

#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_COUNTCHAR
bool countChar(char * filename, int * counts, int size)
{
  // open a file whose name is filename for reading
  FILE *fle = fopen(filename, "r");
  // if fopen fails, return false. Do NOT fclose
  if (fle == NULL)
    {
      // printf("FAILURE");
      return false;
    }
  // if fopen succeeds, read every character from the file
  int onechar = 0;
  int i;

  for (i = 0; i < size; i++)
    counts[i] = 0;
  
  while (1)
    {
      onechar = fgetc(fle);
      if (onechar == EOF)
	{
	  break;
	}
      if (onechar == -1)
	{
	  break;
	}
      if (onechar >= 0 && onechar <= (size - 1))
	{
	  counts[onechar] = counts[onechar] + 1;
	}
    }

  fclose(fle);
  // if a character (call it onechar) is between
  // 0 and size - 1 (inclusive), increase
  // counts[onechar] by one
  // You should *NOT* assume that size is 256
  // reemember to call fclose
  // you may assume that counts already initialized to zero
  // size is the size of counts
  // you may assume that counts has enough memory space 
  //
  // hint: use fgetc
  // Please read the document of fgetc carefully, in particular
  // when reaching the end of the file
  //
  return true;
}
#endif

#ifdef TEST_PRINTCOUNTS
void printCounts(int * counts, int size)
{
  // print the values in counts in the following format
  // each line has three items:
  int i;
  char onechar;
  for (i = 0; i < size; i++)
    {
      while (counts[i] == 0)
	{
	  i++;
	}
      if (i == size)
	{
	  break;
	}
      if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
	{
	  onechar = i;
	}
      else
	{
	  onechar = 32;
	}
      printf("%d, %c, %d\n", i, onechar, counts[i]);
    }
      
  // ind, onechar, counts[ind]
  // ind is between 0 and size - 1 (inclusive)
  // onechar is printed if ind is between 'a' and 'z' or
  // 'A' and 'Z'. Otherwise, print space
  // if counts[ind] is zero, do not print
}
#endif
