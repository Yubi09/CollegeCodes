#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
  int data;
  struct node *next;
} Node;

Node *front = NULL;
Node *rear = NULL;

void enqueue()
{
  int x;
  printf("Enter the value: ");
  scanf("%d", &x);
  Node *newNode;
  newNode = (Node *)malloc(sizeof(Node));
  newNode->data = x;
  newNode->next = NULL;
  if (rear == 0)
  {
    front = rear = newNode;
  }
  else
  {
    rear->next = newNode;
    rear = newNode;
  }
}

void dequeue()
{
  Node *temp = front;
  if (front == NULL && rear == NULL)
  {
    printf("The queue is empty\n");
    return;
  }
  else if (front == rear)
  {
    printf("The last dequeued element is: %d\n", temp->data);
    front = rear = NULL;
    free(temp);
  }
  else
  {
    front = front->next;
    printf("Dequeued: %d\n", temp->data);
    free(temp);
  }
}

void display()
{
  Node *temp = front;
  if (front == NULL && rear == NULL)
  {
    printf("Queue is empty\n");
  }
  else
  {
    while (temp != NULL)
    {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

void peek()
{
  if (front == NULL && rear == NULL)
  {
    printf("The queue is empty\n");
  }
  else
  {
    printf("The element in front is %d\n", front->data);
  }
}

int main()
{
  int ch;
  while (1)
  {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enqueue();
      break;
    case 2:
      dequeue();
      break;
    case 3:
      peek();
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...\n");
      exit(1);
    default:
      break;
    }
  }

  return 0;
}