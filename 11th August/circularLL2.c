#include <stdio.h>
#include <stdlib.h>
// NGB
int count = 0;
struct node
{
  int data;
  struct node *next;
};

struct node *head = NULL;

struct node *create(struct node *head)
{
  struct node *ptr, *newnode;
  int num;

  printf("Enter data: ");
  scanf("%d", &num);

  while (num != -1)
  {
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = num;

    if (head == NULL)
    {
      head = ptr = newnode;
      head->next = head;
      count++; // NGB
    }

    else
    {
      ptr->next = newnode;
      ptr = ptr->next;
      count++; // NGB
    }

    printf("Enter data: ");
    scanf("%d", &num);
  }
  newnode->next = head;

  return head;
}

struct node *display(struct node *head)
{
  struct node *ptr;
  ptr = head;

  if (head == NULL)
  {
    printf("\nList is Empty..\n\n");
  }
  else
  {
    printf("\nLinked List is--> ");
    while (ptr->next != head)
    {
      printf("%d -> ", ptr->data);
      ptr = ptr->next;
    }
    printf("%d", ptr->data);
    printf("\n\n");
  }
  return head;
}

struct node *insert_beg(struct node *head)
{
  struct node *ptr, *newnode, *preptr;
  int num;

  newnode = (struct node *)malloc(sizeof(struct node));

  printf("Enter the new data: ");
  scanf("%d", &num);
  preptr = ptr = head;
  // NGB
  if (head == NULL)
  {
    newnode->data = num;
    head = newnode;
    newnode->next = head;
    ++count;
    return head;
  }
  // if (head->next == head)
  // {
  //     newnode->data = num;
  //     newnode->next = ptr;
  //     ptr->next = newnode;
  //     head = newnode;
  //     ++count;
  //     return head;
  // }
  // NGB

  newnode->data = num;

  while (ptr->next != head)
  {
    ptr = ptr->next;
  }

  newnode->next = preptr;
  ptr->next = newnode;
  head = newnode;
  count++;
  return head;
}
struct node *insert_end(struct node *head)
{
  struct node *ptr, *newnode;
  int num;

  newnode = (struct node *)malloc(sizeof(struct node));

  printf("Enter the new data: ");
  scanf("%d", &num);

  ptr = head;
  newnode->data = num;
  // NGB
  if (head == NULL)
  {
    newnode->next = newnode;
    head = newnode;
    count++;
    return head;
  }
  // NGB
  while (ptr->next != head)
  {
    ptr = ptr->next;
  }

  ptr->next = newnode;
  newnode->next = head;
  count++;
  return head;
}

struct node *insert_position(struct node *head)
{
  struct node *ptr, *newnode;
  int num, value, i;

  if (head == NULL)
  {
    return (insert_beg(head));
  }

  printf("Enter the position of Insertion: ");
  scanf("%d", &value);

  // NGB

  if (value == 1)
  {
    return (insert_beg(head));
  }
  else if (value == (count + 1))
  {
    return (insert_end(head));
  }
  else if ((value < 1) || (count <= 0) || (value > count))
  {
    printf("\ncount = %d\nPosition out of Bounds\n", count);
  }
  else
  {
    printf("Enter the new data: ");
    scanf("%d", &num);
    // NGB
    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = num;
    ptr = head;
    for (i = 1; i < (value - 1) && ptr != NULL; i++)
    {
      ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;
    count++;
  }
  return head;
}

struct node *delete_beg(struct node *head)
{
  struct node *ptr, *preptr;

  if (head == NULL)
  {
    printf("\nUnderflow Condition!!\n\n");
  }

  else
  {
    preptr = ptr = head;
    // NGB
    if (head->next == head)
    {
      count--;
      free(head);
      head = NULL;
      return head;
    }
    // NGB
    while (ptr->next != head)
    {
      ptr = ptr->next;
    }

    ptr->next = preptr->next;
    head = ptr->next;
    count--;
    free(preptr);
  }
  return head;
}

struct node *delete_end(struct node *head)
{
  struct node *ptr, *preptr;

  ptr = preptr = head;

  if (head == NULL)
  {
    printf("\nUnderflow Condition!!\n\n");
    return head;
  }

  if (head->next == head)
  {
    count--;
    free(head);
    head = NULL;
    return head;
  }

  while (ptr->next != head)
  {
    preptr = ptr;
    ptr = ptr->next;
  }

  preptr->next = head;
  count--;
  free(ptr);

  return head;
}

struct node *delete_position(struct node *head)
{
  struct node *ptr, *preptr;
  int value, i;

  if (head == NULL)
  {
    printf("\nUnderflow Condition!!\n\n");
    return head;
  }

  if (head->next == head)
  {
    count--;
    free(head);
    head = NULL;
    return head;
  }

  ptr = preptr = head;

  printf("Enter the position for deletion: ");
  scanf("%d", &value);

  for (i = 1; i < value && ptr != NULL; i++)
  {
    preptr = ptr;
    ptr = ptr->next;
  }
  if (value == 1)
  {
    return (delete_beg(head));
  }

  if (value == count)
  {
    return (delete_end(head));
  }

  if ((value < 1) || (value > count) || (count <= 0))
  {
    printf("\nPosition of out of bounds\n");
    return head;
  }
  preptr->next = ptr->next;
  count--;
  free(ptr);

  return head;
}

int main()
{
  int choice;

  do
  {
    printf("\n1. Create Linked List\n2. Display Linked List\n3. Insert at begining\n4. Insert at a certain position\n5. Insert at end\n6. Delete at begining\n7. Delete at a certain position\n8. Delete at end\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      head = create(head);
      break;

    case 2:
      head = display(head);
      break;

    case 3:
      head = insert_beg(head);
      break;

    case 4:
      head = insert_position(head);
      break;

    case 5:
      head = insert_end(head);
      break;

    case 6:
      head = delete_beg(head);
      break;

    case 7:
      head = delete_position(head);
      break;

    case 8:
      head = delete_end(head);
      break;
    }
  } while (choice != 9);

  return 0;
}