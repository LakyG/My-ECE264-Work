// ***
// *** You MUST modify this file
// ***

#include "josephus.h"
#include <stdio.h>
#include <stdbool.h>

#ifdef TEST_JOSEPHUS
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails,
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements

  int i = 0;
  int numElementsLeft = n; //the number of elements left in the array
  int stepsToEnd = n; //the number of steps till the end of the array
  int numSteps; //the number of steps to take forward in the array
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  do
  {

    if(k > n && k % n != 0)
    {
      numSteps = k % n;
    }
    else if(k > n && k % n == 0)
    {
      numSteps = n;
    }
    else
    {
      numSteps = k;
    }

    while(arr[i + numSteps - 1] == 'X')
    {
      i++;
    }

    printf("%d\n", i + numSteps - 1);
    arr[i + numSteps - 1] = 'X';
    numElementsLeft--;
    stepsToEnd = n - (i + numSteps);

    if(stepsToEnd == 0)
    {
      i = 0;
      stepsToEnd = n;
    }
    else
    {
      i = i + numSteps;
    }
		
  } while(numElementsLeft > 0)


  // print the last one




  // release the memory of the array
  free (arr);
}
#endif
