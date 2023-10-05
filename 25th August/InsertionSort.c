#include <stdio.h>
#include <stdlib.h>

void insertionSort(int *arr, int n)
{
  int i, key, j;
  for (i = 1; i < n; i++)
  {
    key = arr[i];
    j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
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

  insertionSort(arr, n);

  printf("Sorted array: \n");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}