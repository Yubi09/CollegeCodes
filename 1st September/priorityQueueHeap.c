#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Node
{
  int data;
  int priority;
};

struct PriorityQueue
{
  struct Node heap[MAX_SIZE];
  int size;
};

void enqueue(struct PriorityQueue *pq, int data, int priority)
{
  if (pq->size >= MAX_SIZE)
  {
    printf("Queue is full. Cannot enqueue.\n");
    return;
  }

  pq->size++;
  int i = pq->size - 1;
  pq->heap[i].data = data;
  pq->heap[i].priority = priority;

  while (i > 0 && pq->heap[(i - 1) / 2].priority > pq->heap[i].priority)
  {
    struct Node temp = pq->heap[i];
    pq->heap[i] = pq->heap[(i - 1) / 2];
    pq->heap[(i - 1) / 2] = temp;

    i = (i - 1) / 2;
  }
}

struct Node dequeue(struct PriorityQueue *pq)
{
  if (pq->size <= 0)
  {
    printf("Queue is empty. Cannot dequeue.\n");
    struct Node empty_node = {0, 0};
    return empty_node;
  }

  if (pq->size == 1)
  {
    pq->size--;
    return pq->heap[0];
  }

  struct Node root = pq->heap[0];
  pq->heap[0] = pq->heap[pq->size - 1];
  pq->size--;

  int i = 0;
  while (1)
  {
    int left_child = 2 * i + 1;
    int right_child = 2 * i + 2;
    int smallest = i;

    if (left_child < pq->size && pq->heap[left_child].priority < pq->heap[smallest].priority)
      smallest = left_child;

    if (right_child < pq->size && pq->heap[right_child].priority < pq->heap[smallest].priority)
      smallest = right_child;

    if (smallest != i)
    {
      struct Node temp = pq->heap[i];
      pq->heap[i] = pq->heap[smallest];
      pq->heap[smallest] = temp;
      i = smallest;
    }
    else
    {
      break;
    }
  }

  return root;
}

void display(struct PriorityQueue *pq)
{
  if (pq->size == 0)
  {
    printf("Queue is empty.\n");
    return;
  }

  printf("Priority Queue:\n");
  for (int i = 0; i < pq->size; i++)
  {
    printf("(%d, %d) ", pq->heap[i].data, pq->heap[i].priority);
  }
  printf("\n");
}

int main()
{
  struct PriorityQueue pq = {{0, 0}, 0};
  int choice, data, priority;

  do
  {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter data and priority: ");
      scanf("%d %d", &data, &priority);
      enqueue(&pq, data, priority);
      break;
    case 2:
      dequeue(&pq);
      break;
    case 3:
      display(&pq);
      break;
    case 4:
      printf("Exiting...\n");
      break;
    default:
      printf("Invalid choice. Please try again.\n");
    }
  } while (choice != 4);

  return 0;
}
