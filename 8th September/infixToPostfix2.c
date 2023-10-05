#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
char infix[max];
char postfix[max];
typedef struct node
{
  int data;
  struct node *next;
} stack;
stack *top = NULL;
void push(stack *st, int x)
{
  stack *nn = (stack *)malloc(sizeof(stack));
  nn->data = x;
  if (top == NULL)
  {
    top = nn;
    nn->next = NULL;
    return;
  }
  nn->next = top;
  top = nn;
}
int isEmpty(stack *st)
{
  if (top == NULL)
  {
    return 1;
  }
  return 0;
}
char pop(stack *st)
{
  if (top == NULL)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  stack *temp = top;
  int n = temp->data;
  top = top->next;
  free(temp);
  return n;
}
char peek(stack *st)
{
  if (top == NULL)
  {
    return -1;
  }
  return top->data;
}
int precedence(char c)
{

  switch (c)
  {
  case '*': 
  case '/': 
  case '%': 
    return 2;
  case '+': 
  case '-': 
    return 1;
  default:
    return 0;
  }
}
int space(char c)
{
  if (c == ' ' || c == '\t')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
void print()
{
  int i = 0;      
  printf("Equivalent postfix: ");
  while (postfix[i])              
  {
    printf("%c", postfix[i]); 
    i++;                     
  }
  printf("\n");
}
void infixToPostfix(stack *ptr)
{
  int i, j = 0;
  char n, s;
  for (i = 0; i < strlen(infix); i++)
  {
    s = infix[i];
    if (!space(s))
    {
      switch (s)
      {
      case '(':
        push(ptr, s);
        break;
      case ')':
        while ((n = pop(ptr)) != '(')
        {
          postfix[j++] = n;
        }
        break;
      case '+':
      case '-':
      case '*':
      case '/':
      case '%':
        while (!isEmpty(ptr) && precedence(peek(ptr)) >=
                                    precedence(s))
        {
          postfix[j++] = pop(ptr);
        }
        push(ptr, s);
        break;
      default:
        postfix[j++] = s;
      }
    }
  }
  while (!isEmpty(ptr))
  {
    postfix[j++] = pop(ptr);
  }
  postfix[j] = '\0';
}
int evaluatePostfix(stack *ptr)
{
  int i, a, b;
  for (i = 0; i < strlen(postfix); i++)
  {
    if (postfix[i] >= '0' && postfix[i] <= '9')
    {
      push(ptr, postfix[i] - '0');
    }
    else
    {
      a = pop(ptr);
      b = pop(ptr);
      switch (postfix[i])
      {
      case '+':
        push(ptr, (b + a));
        break;
      case '-':
        push(ptr, (b - a));
        break;
      case '*':
        push(ptr, (b * a));
        break;
      case '/':
        push(ptr, (b / a));
        break;
      case '%':
        push(ptr, (b % a));
      }
    }
  }
  int x = pop(ptr);
  return x;
}
int main()
{
  stack *ptr = (stack *)malloc(sizeof(stack));
  printf("Infix : ");
  gets(infix);
  infixToPostfix(ptr);
  print();
  char ans = evaluatePostfix(ptr);
  printf("\n%d\n", ans);
  return 0;
}