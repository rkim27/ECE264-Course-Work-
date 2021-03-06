// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  FILE * fle = fopen(filename, "r");
  int len;
  // return false if fopen fails
  if (fle == NULL)
  {
	  return false;
  }
  // use fseek to go to the end of the file
  if (fseek(fle, 0, SEEK_END) != 0)
  {
	  fclose(fle);
	  return false;
  }
  // check whether fseek fails
  // if fseek fails, fclose and return false
  // use ftell to determine the size of the file
  len = ftell(fle);
  // use fseek to go back to the beginning of the file
  // check whether fseek fails
  if (fseek(fle, 0, SEEK_SET) != 0)
  {
	  fclose(fle);
	  return false;
  }
  // if fseek fails, fclose and return false
  
  // the number of integers is the file's size divided by
  *size = len/sizeof(int);
  // size of int  

  // allocate memory for the array
  *arr = malloc(sizeof(int) * *size);

  // if malloc fails, fclose and return false
  if (*arr == NULL)
  {
	  fclose(fle);
	  return false;
  }

  // use fread to read the number of integers in the file
  int num;
  num = fread(*arr, sizeof(int), *size, fle);
  if (num != *size)
  {
	  free(*arr);
	  fclose(fle);
	  return false;
  }

  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
  
  // if fread succeeds
  // close the file
  fclose(fle);
  
  // update the argument for the array address 
  // update the size of the array
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  FILE * fle = fopen(filename, "w");
  // if fopen fails, return false
  if (fle == NULL)
  {
	  return false;
  }
  
  // use fwrite to write the entire array to a file
  if (fwrite(arr, sizeof(int), size, fle) == size)
  {
	  fclose(fle);
	  return true;
  }
  else
  {
	  fclose(fle);
	  return false;
  }
  
  // check whether all elements of the array have been written
  // fclose  
  // if not all elements have been written, return false
  // if all elements have been written, return true
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif
   int i;
   int it = 0;
   int  r1 = m - l + 1;
   int r2 = r - m;
   int ind  = l;
  // if one or both of the arrays are empty, do nothing
   if ((l <= m) && ((m+1) <= r))
   {
	   int * arr1 = malloc(sizeof(int) * r1);
	   int * arr2 = malloc(sizeof(int) * r2);
		
	   for ( i=0; i < r1; i++)
	   {
		   arr1[i] = arr[l+i];
	   }
	   for ( i=0; i < r2; i++)
	   {
		   arr2[i] = arr[m + 1 + i];
	   }
    i = 0;
	while ( i < r1 &&  it < r2)
	{
		if (arr1[i] <= arr2[it])
		{
			arr[ind] = arr1[i];
			i++;
		}
		else
		{
			arr[ind] = arr2[it];
			it++;
		}
		ind++;
	}
	while (i < r1)
	{
		arr[ind] = arr1[i];
		i++;
		ind++;
	}
	while (it <  r2)
	{
		arr[ind] = arr2[it];
		it++;
		ind++;
	}
	free(arr1);
	free(arr2);
   }
   

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array

  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif
   // if the array has no or one element, do nothing
  if (r <= l)
 {	 
	return;
 }
     int m = (r + l)/2;
	 mergeSort(arr, l, m);
	 mergeSort(arr, m+1, r );
	 merge(arr, l, m, r);
 

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
} 
#endif
