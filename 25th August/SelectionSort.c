#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n)
{
  int i, j;
  int min;
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i+1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
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

  selectionSort(arr, n);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}