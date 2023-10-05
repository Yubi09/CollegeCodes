#include <stdio.h>
#include <stdlib.h>

void reverse(int[], int);

void swap(int *a, int *b)
{
  *a = *a ^ *b;
  *b = *a ^ *b;
  *a = *a ^ *b;
}

int main()
{
  int n, i;
  printf("Enter the length of the array: ");
  scanf("%d", &n);
  int *arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements in the array!!!\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  reverse(arr, n);

  return 0;
}

void reverse(int arr[], int n)
{
  int i;
  int start = 0;
  int end = n - 1;
  while (start < end)
  {
    swap(&arr[start], &arr[end]);
    start++;
    end--;
  }
  printf("The reversed array is \n");
  for (i = 0; i < n; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}