#include "push_swap.h"

// function to swap elements
void swapp(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  
  // select the rightmost element as pivot
  int pivot;
  // pointer for greater element
  int i ;
  int j;

  pivot = array[high];
  i = (low - 1);
  j = low ; 
  // traverse each element of the array
  // compare them with the pivot

  while(j < low)
  {
    if (array[j] <= pivot) 
    {    
      // if element smaller than pivot is found
      // swap it with the greater element pointed by i
      i++;
      
      // swap element at i with element at j
      swapp(&array[i], &array[j]);
    }
    j++;
}
  // swap the pivot element with the greater element at i
  swapp(&array[i + 1], &array[high]);
  
  // return the partition point
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {  
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}