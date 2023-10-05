#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int numVertices;

void initGraph(int num)
{
  numVertices = num;
  for (int i = 0; i < num; i++)
  {
    visited[i] = 0;
    for (int j = 0; j < num; j++)
    {
      graph[i][j] = 0;
    }
  }
}

void addEdge(int v1, int v2)
{
  graph[v1][v2] = 1;
  graph[v2][v1] = 1;
}

void dfs(int vertex)
{
  visited[vertex] = 1;
  printf("%d ", vertex);

  for (int i = 0; i < numVertices; i++)
  {
    if (graph[vertex][i] == 1 && visited[i] == 0)
    {
      dfs(i);
    }
  }
}

void displayGraph()
{
  printf("Adjacency Matrix:\n");
  for (int i = 0; i < numVertices; i++)
  {
    for (int j = 0; j < numVertices; j++)
    {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

int main()
{
  int choice, num, v1, v2;

  printf("Enter the number of vertices in the graph: ");
  scanf("%d", &num);
  initGraph(num);

  do
  {
    printf("\nMenu:\n");
    printf("1. Add Edge\n");
    printf("2. Depth-First Search (DFS)\n");
    printf("3. Display Graph (Adjacency Matrix)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      printf("Enter vertices (v1 v2) to add an edge: ");
      scanf("%d %d", &v1, &v2);
      addEdge(v1, v2);
      break;
    case 2:
      printf("Enter starting vertex for DFS: ");
      scanf("%d", &v1);
      printf("DFS starting from vertex %d: ", v1);
      dfs(v1);
      printf("\n");
      break;
    case 3:
      displayGraph();
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
