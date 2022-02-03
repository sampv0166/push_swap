#include "push_swap.h"

void swapp(int* a, int* b)
{
    int t;

    t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot; 
    int i; 
    int j;

    pivot = arr[high];
    i = (low - 1);
    j = low;
  while(j <= high - 1)
  {
        if (arr[j] < pivot)
        {
            i++;
            swapp(&arr[i], &arr[j]);
        }
    j++;
  }
    swapp(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi;
        pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}