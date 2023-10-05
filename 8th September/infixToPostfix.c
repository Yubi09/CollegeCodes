#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct Node
{
  char data;
  struct Node *next;
} Node;

typedef struct
{
  Node *top;
} Stack;

void initialize(Stack *s)
{
  s->top = NULL;
}

void push(Stack *s, char data)
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = s->top;
  s->top = newNode;
}

char pop(Stack *s)
{
  if (s->top == NULL)
  {
    printf("Error: Stack is empty\n");
    return '\0';
  }
  Node *temp = s->top;
  char data = temp->data;
  s->top = temp->next;
  free(temp);
  return data;
}

int isEmpty(Stack *s)
{
  return s->top == NULL;
}

char top(Stack *s)
{
  if (s->top == NULL)
  {
    return '\0';
  }
  return s->top->data;
}

int isOperator(char ch)
{
  return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int getPrecedence(char op)
{
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
  Stack stack;
  initialize(&stack);
  int i, j;

  for (i = 0, j = 0; infix[i] != '\0'; i++)
  {
    if (isdigit(infix[i]))
    {
      postfix[j++] = infix[i];
    }
    else if (infix[i] == '(')
    {
      push(&stack, infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (top(&stack) != '(' && !isEmpty(&stack))
      {
        postfix[j++] = pop(&stack);
      }
      if (top(&stack) == '(')
      {
        pop(&stack); // Pop '('
      }
    }
    else if (isOperator(infix[i]))
    {
      while (!isEmpty(&stack) && getPrecedence(top(&stack)) >= getPrecedence(infix[i]))
      {
        postfix[j++] = pop(&stack);
      }
      push(&stack, infix[i]);
    }
  }

  while (!isEmpty(&stack))
  {
    postfix[j++] = pop(&stack);
  }

  postfix[j] = '\0';
}

int evaluatePostfix(char postfix[])
{
  Stack stack;
  initialize(&stack);

  for (int i = 0; postfix[i] != '\0'; i++)
  {
    if (isdigit(postfix[i]))
    {
      push(&stack, postfix[i] - '0');
    }
    else if (isOperator(postfix[i]))
    {
      int operand2 = pop(&stack);
      int operand1 = pop(&stack);
      int result;
      switch (postfix[i])
      {
      case '+':
        result = operand1 + operand2;
        break;
      case '-':
        result = operand1 - operand2;
        break;
      case '*':
        result = operand1 * operand2;
        break;
      case '/':
        result = operand1 / operand2;
        break;
      }
      push(&stack, result);
    }
  }

  return pop(&stack);
}

int main()
{
  char infix[100];
  printf("Enter an infix expression: ");
  scanf("%s", infix);

  char postfix[100];
  infixToPostfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  int result = evaluatePostfix(postfix);
  printf("Result: %d\n", result);

  return 0;
}
