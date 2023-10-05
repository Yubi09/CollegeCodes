#include <stdio.h>
#include <stdlib.h>

int n;
int front = -1;
int rear = -1;

void enqueue(int *q)
{
  int x;
  if ((rear + 1) % n == front)
  {
    printf("Queue is full\n");
    return;
  }
  printf("Enter a number: ");
  scanf("%d", &x);
  if (front == -1 && rear == -1)
  {
    front = rear = 0;
    q[rear] = x;
  }
  else
  {
    rear = (rear + 1) % n;
    q[rear] = x;
  }
}

void dequeue(int *q)
{
  if (front == -1 && rear == -1)
  {
    printf("The queue is empty\n");
    return;
  }
  else if (front == rear)
  {
    printf("The last dequeued element is %d\n", q[front]);
    front = rear = -1;
  }
  else
  {
    printf("dequeued %d\n", q[front]);
    front = (front + 1) % n;
  }
}

void display(int *q)
{
  int i = front;
  if (front == -1 && rear == -1)
  {
    printf("Queue is empty\n");
  }
  else
  {
    printf("Queue is: \n");
    while (i != rear)
    {
      printf("%d ", q[i]);
      i = (i + 1) % n;
    }
    printf("%d\n", q[rear]);
  }
}

int main()
{
  int ch;
  printf("Enter the size of the queue: ");
  scanf("%d", &n);
  int *q = (int *)malloc(n * sizeof(int));
  while (1)
  {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
      enqueue(q);
      break;
    case 2:
      dequeue(q);
      break;
    case 3:
      display(q);
      break;
    case 4:
      printf("Exiting...\n");
      free(q);
      exit(1);
    default:
      break;
    }
  }

  return 0;
}