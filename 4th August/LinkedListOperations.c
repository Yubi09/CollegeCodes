#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

struct Node *createNode(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (newNode == NULL)
  {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

struct Node *createList(struct Node *head)
{
  struct Node *ptr;
  int value, cont = 0;
  printf("Enter the value you want to enter: ");
  scanf("%d", &value);
  while (1)
  {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL)
    {
      head = newNode;
      ptr = head;
    }
    else
    {
      ptr->next = newNode;
      ptr = ptr->next;
    }
    printf("Enter 0 to continue and 1 to discontinue: ");
    scanf("%d", &cont);
    if (cont == 1)
    {
      break;
    }
    else
    {
      printf("Enter the value: ");
      scanf("%d", &value);
    }
  }
  return head;
}

void display(struct Node *head)
{
  struct Node *current = head;
  while (current != NULL)
  {
    printf("%d -> ", current->data);
    current = current->next;
  }
  printf("NULL\n");
}

struct Node *insertFront(struct Node *head, int data)
{
  struct Node *newNode = createNode(data);
  newNode->next = head;
  return newNode;
}

struct Node *insertEnd(struct Node *head, int data)
{
  struct Node *newNode = createNode(data);
  if (head == NULL)
  {
    return newNode;
  }
  struct Node *current = head;
  while (current->next != NULL)
  {
    current = current->next;
  }
  current->next = newNode;
  return head;
}

struct Node *insertAtPosition(struct Node *head)
{
  int data, position, i;
  printf("Enter position: ");
  scanf("%d", &position);
  if (position < 1)
  {
    printf("Invalid position.\n");
    return head;
  }
  if (position == 1 || head == NULL)
  {
    return insertFront(head, data);
  }
  int k = position;
  struct Node *check = head;
  while(check != NULL && k != 1){
    check = check->next;
    k--;
  }
  if (check == NULL)
  {
    printf("Out of bounds!!!\n");
    return head;
  }
  printf("Enter data: ");
  scanf("%d", &data);
  struct Node *newNode = createNode(data);
  struct Node *current = head;
  for (i = 1; i < position - 1; i++)
  {
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
  return head;
}

struct Node *deleteFront(struct Node *head)
{
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return head;
  }
  struct Node *newNode = head;
  head = newNode->next;
  free(newNode);
  if (head == NULL)
  {
    printf("NULL\n");
  }
  return head;
}

struct Node *deleteEnd(struct Node *head)
{
  if (head == NULL)
  {
    printf("The list is empty.\n");
    return head;
  }
  if (head->next == NULL)
  {
    head = deleteFront(head);
    return head;
  }
  struct Node *ptr = head;
  while(ptr->next->next != NULL)
  {
    ptr = ptr->next;
  }
  struct Node *temp = ptr->next;
  ptr->next = NULL;
  free(temp);
  return head;
}

struct Node *deleteAtPosition(struct Node *head)
{
  int position, i;
  printf("Enter position: ");
  scanf("%d", &position);
  if (position < 1 || head == NULL)
  {
    printf("Invalid position.\n");
    return head;
  }
  struct Node *temp = head;
  if (position == 1)
  {
    head = head->next;
    free(temp);
    return head;
  }
  int k = position;
  struct Node *check = head;
  while (check != NULL && k != 1)
  {
    check = check->next;
    k--;
  }
  if (check == NULL)
  {
    printf("Out of bounds!!!\n");
    return head;
  }
  struct Node *prev = NULL;
  for (i = 1; i < position && temp != NULL; i++)
  {
    prev = temp;
    temp = temp->next;
  }
  if (temp == NULL)
  {
    printf("Position out of bounds.\n");
    return head;
  }
  prev->next = temp->next;
  free(temp);
  return head;
}

int main()
{
  struct Node *head = NULL;
  int choice, data, position;

  do
  {
    printf("1. Create the list\n");
    printf("2. Insert at the beginning\n");
    printf("3. Insert at the end\n");
    printf("4. Insert at a specific position\n");
    printf("5. Delete from the beginning\n");
    printf("6. Delete from the end\n");
    printf("7. Delete from a specific position\n");
    printf("8. Display the list\n");
    printf("9. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
      case 1:
      head = createList(head);
      break;
      case 2:
      printf("Enter data: ");
      scanf("%d", &data);
      head = insertFront(head, data);
      break;
      case 3:
      printf("Enter data: ");
      scanf("%d", &data);
      head = insertEnd(head, data);
      break;
      case 4:
      head = insertAtPosition(head);
      break;
      case 5:
      head = deleteFront(head);
      break;
      case 6:
      head = deleteEnd(head);
      break;
      case 7:
      
      head = deleteAtPosition(head);
      break;
      case 8:
      display(head);
      break;
      case 9:
      printf("Exiting...\n");
      break;
      default:
      printf("Invalid choice.\n");
    }
  } while (choice != 9);

  struct Node *current = head;
  while (current != NULL)
  {
    struct Node *temp = current;
    current = current->next;
    free(temp);
  }

  return 0;
}
