#include <stdio.h>
#include<stdlib.h>

void modifiedBubbleSort(int *arr, int n)
{
  int i, j;
  int swapped = 1;
  for (i = 0; i < n - 1 && swapped == 1; i++)
  {
    swapped = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        swapped = 1;
      }
    }
  }
}

int main()
{
  int n, i;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the values in the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  modifiedBubbleSort(arr, n);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}