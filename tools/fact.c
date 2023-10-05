#include <stdio.h>

int recurFact(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * recurFact(n - 1);
  }
}

int main()
{
  int a;
  printf("Enter the value for factorial: ");
  scanf("%d", &a);
  printf("The factorial is: %d", recurFact(a));
  return 0;
}