#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

void modifiedBubbleSort()
{
  int *arr, n, i, j, k, swapped = 1;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements in the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  for(i = 0; i < n - 1 && swapped == 1; i++)
  {
    swapped = 0;
    for (j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(&arr[j], &arr[j+1]);
        swapped = 1;
      }
    }
    printf("The array in iteration %d is:\n", i);
    for (k = 0; k < n; k++)
    {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

void insertionSort()
{
  int i, *arr, n, k, key, j;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements in the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
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
    printf("The array in iteration %d is:\n", i);
    for (k = 0; k < n; k++)
    {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

void selectionSort()
{
  int i, j, min, k, *arr, n;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &n);
  arr = (int *)malloc(n * sizeof(int));
  printf("Enter the elements in the array:\n");
  for (i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }
  for (i = 0; i < n - 1; i++)
  {
    min = i;
    for (j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min])
      {
        min = j;
      }
    }
    swap(&arr[i], &arr[min]);
    printf("The array in iteration %d is:\n", i);
    for (k = 0; k < n; k++)
    {
      printf("%d ", arr[k]);
    }
    printf("\n");
  }
}

int main()
{
  int choice;
  while (1)
  {
    printf("Enter 1 to sort the array with bubble sort\n");
    printf("Enter 2 to sort the array with insertion sort\n");
    printf("Enter 3 to sort the array with selection sort\n");
    printf("Enter 4 to Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
        modifiedBubbleSort();
        break;
      case 2:
        insertionSort();
        break;
      case 3:
        selectionSort();
        break;
      case 4:
        printf("Exiting...\n");
        exit(1);
      default:
        printf("Wrong choice\n");
    }
  }
  
  return 0;
}