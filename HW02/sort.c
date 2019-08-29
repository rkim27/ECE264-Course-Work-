// ***
// *** You MUST modify this file, only the ssort function
// ***

#include "sort.h"
#include <stdio.h>

// DO NOT MODIFY THIS FUNCTION
bool checkOrder(int * arr, int size)
// a static function is visible only in this file
// This function returns true if the array elements are
// in the ascending order.
// false, otherwise
{
  int ind;
  for (ind = 0; ind < (size - 1); ind ++)
    {
      if (arr[ind] > arr[ind + 1])
	{
	  return false;
	}
    }
  return true;
}


// YOU MUST MODIFY THIS FUNCTION
#ifdef TEST_SORT
void ssort(int * arr, int size)
{
  int i; 
  int j;
  int min;   //Lower value holder
  int temp;   //V
  int num1;
  int num2;

  for (i = 0; i < size - 1; i++) //For loop for place in array
    {
      min = i;
      for (j = i + 1; j < size; j++) //For loop that goes through the next elements in the array until a smaller value is found
	{
	  if (arr[j] < arr[min])
	    min = j;
	}
      if (i != min) //If a smaller value is found swap the two numbers
	{
	  num1 = arr[i];
	  num2 = arr[min];

	  temp = num1;
	  arr[i] = num2;
	  arr[min] = temp;
	}
    }
  return;
}
#endif
