// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
    // initialize all elements
    int i; //iterations
    int left = n; //How many people left
    int pl = 0;//Place in array at end of for loop
    int count;
    int it;
    
    // counting to k
  
    while (left != 1) //Loops until only 1 person left
        {
            count = 1;

            for (i = pl; i != -1; i++) //Goes through array starting from last position
	        {   
	            for (it = i; it != -1; it++)
	            {
	                if (i >= n) //Check if out of array bounds
	                {
	                    i = 0;
                        }
                        if (arr[i] == 'X') //Skip if marked x
	                {
	                    i++;
	                }
	                if (i >= n) //Check if out of array bounds again
	                {
	                    i = 0;
                        }
	                if (arr[i] != 'X')
	                {
	                    it = -2;
	                }
	            }
	            
	            arr[i] = count;
	            count++;
	  
	            if (arr[i] == k)
	            { 
	                arr[i] = 'X'; //Elimated by inserting value of x
	                pl = i + 1; //New start place in array
	                printf("%d\n", i);
	                left--;
	                i = -2; //Exits for loop
	            }
	        }
        }
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  // print the last one
  
  for (i = 0; i < n; i++)
    {
      if (arr[i] != 'X')
	 printf("%d\n", i);
    }
  // release the memory of the array
  free (arr);
}
#endif
