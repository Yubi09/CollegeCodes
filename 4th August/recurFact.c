#include <stdio.h>

int recurFac(int n)
{
  if (n == 0 || n == 1)
  {
    return 1;
  }
  else
  {
    return n * recurFac(n - 1);
  }
}

int main()
{
  int a;
  printf("Enter the number: ");
  scanf("%d", &a);
  int k = recurFac(a);
  printf("The factorial of %d is %d\n", a, k);
  return 0;
}
