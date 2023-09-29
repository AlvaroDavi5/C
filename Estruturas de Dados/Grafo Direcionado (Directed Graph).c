#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISTANCE 999999
#define UNKNOWN 0
#define VISITED 1
#define FINISHED 2

struct graph
{
	int verticesAmount;
	int edgesAmount;
	float **edges;
};
typedef struct graph Graph;

Graph *createGraph(int verticesAmount);
void destroyGraph(Graph *graph);
bool addEdge(Graph *graph, unsigned int src, unsigned int dest, float weight);
bool hasEdge(Graph *graph, unsigned int src, unsigned int dest);
void depthFirstSearch(Graph *graph, int vertex, unsigned int *visitedVertices);
void breadthFirstSearch(Graph *graph, int vertex, unsigned int *visitedVertices, int *verticesQueue);
void displayGraphEdges(Graph *graph);
void displayGraphTable(Graph *graph);

int main()
{
	Graph *graph = createGraph(5);

	addEdge(graph, 0, 1, 1.0);
	addEdge(graph, 0, 2, 2.0);
	addEdge(graph, 1, 3, 2.3);
	addEdge(graph, 3, 4, 1.2);
	addEdge(graph, 4, 1, 3.1);
	addEdge(graph, 4, 2, 4.5);

	printf("Table:\n");
	displayGraphTable(graph);
	printf("\nEdges:\n");
	displayGraphEdges(graph);

	int verticesQueue[graph->verticesAmount];
	unsigned int visitedVertices[graph->verticesAmount];

	printf("\nDFS:\n");
	for (int i = 0; i < graph->verticesAmount; i++)
		visitedVertices[i] = UNKNOWN;
	depthFirstSearch(graph, 0, visitedVertices);

	printf("\nBFS:\n");
	for (int i = 0; i < graph->verticesAmount; i++)
		visitedVertices[i] = UNKNOWN;
	breadthFirstSearch(graph, 0, visitedVertices, verticesQueue);

	destroyGraph(graph);

	return 0;
}

Graph *createGraph(int verticesAmount)
{
	Graph *gr = malloc(sizeof(Graph));
	if (gr == NULL)
	{
		printf("Error to allocate memory for graph\n");
		return NULL;
	}

	gr->verticesAmount = verticesAmount;
	gr->edgesAmount = 0;

	gr->edges = (float **)malloc(verticesAmount * sizeof(float *));
	if (gr->edges == NULL)
	{
		free(gr);
		return NULL;
	}

	for (int i = 0; i < verticesAmount; i++)
	{
		gr->edges[i] = (float *)malloc(verticesAmount * sizeof(float));
		if (gr->edges[i] == NULL)
		{
			destroyGraph(gr);
			return NULL;
		}

		for (int j = 0; j < verticesAmount; ++j)
		{
			if (i == j)
				gr->edges[i][j] = 0.0;
			else
				gr->edges[i][j] = MAX_DISTANCE;
		}
	}

	return gr;
}

void destroyGraph(Graph *graph)
{
	if (graph->edges == NULL)
		return;

	for (int i = 0; i < graph->verticesAmount; i++)
	{
		if (graph->edges[i] != NULL)
		{
			free(graph->edges[i]);
		}
	}

	free(graph->edges);
	free(graph);
}

bool addEdge(Graph *graph, unsigned int src, unsigned int dest, float weight)
{
	if (hasEdge(graph, src, dest))
		return false;

	graph->edges[src][dest] = weight;
	graph->edgesAmount++;

	return true;
}

bool hasEdge(Graph *graph, unsigned int src, unsigned int dest)
{
	if (graph == NULL)
		return false;
	else if ((src > graph->verticesAmount - 1) || (dest > graph->verticesAmount - 1))
		return false;

	if (graph->edges[src][dest] < MAX_DISTANCE)
		return true;

	return false;
}

void depthFirstSearch(Graph *graph, int vertex, unsigned int *visitedVertices)
{
	if (graph == NULL || vertex < 0 || vertex >= graph->verticesAmount)
	{
		printf("Invalid input\n");
		return;
	}

	visitedVertices[vertex] = VISITED;
	printf("Visited vertex: %d\n", vertex);

	for (int i = 0; i < graph->verticesAmount; i++)
	{
		float w = graph->edges[vertex][i];
		if (w > 0 && w < MAX_DISTANCE)
		{
			if (visitedVertices[i] == UNKNOWN)
				depthFirstSearch(graph, i, visitedVertices);
			else if (visitedVertices[i] == VISITED)
				printf("Founded visited vertex: %d\n", i);
			else if (visitedVertices[i] == FINISHED)
				printf("Founded finished vertex: %d\n", i);
		}
	}
	visitedVertices[vertex] = FINISHED;
}

void breadthFirstSearch(Graph *graph, int vertex, unsigned int *visitedVertices, int *verticesQueue)
{
	if (graph == NULL || vertex < 0 || vertex >= graph->verticesAmount)
	{
		printf("Invalid input\n");
		return;
	}

	int front = 0;
	int rear = 0;

	verticesQueue[rear++] = vertex;
	visitedVertices[vertex] = VISITED;

	while (front < rear)
	{
		int currentVertex = verticesQueue[front++];
		printf("Visited vertex: %d\n", currentVertex);

		for (int i = 0; i < graph->verticesAmount; i++)
		{
			float w = graph->edges[currentVertex][i];
			if (w > 0 && w < MAX_DISTANCE)
			{
				if (visitedVertices[i] == UNKNOWN)
				{
					verticesQueue[rear++] = i;
					visitedVertices[i] = VISITED;
				}
				else if (visitedVertices[i] == VISITED)
					printf("Founded visited vertex: %d\n", i);
				else if (visitedVertices[i] == FINISHED)
					printf("Founded finished vertex: %d\n", i);
			}
		}

		visitedVertices[currentVertex] = FINISHED;
	}
}

void displayGraphEdges(Graph *graph)
{
	for (int from = 0; from < graph->verticesAmount; from++)
	{
		for (int to = 0; to < graph->verticesAmount; to++)
		{
			float w = graph->edges[from][to];
			if (w > 0 && w < MAX_DISTANCE)
			{
				printf("%d -> %d;\n", from, to);
			}
		}
	}
}

void displayGraphTable(Graph *graph)
{
	printf("   ");
	for (int i = 0; i < graph->verticesAmount; i++)
		printf(" %d | ", i);
	printf("\n");

	for (int i = 0; i < graph->verticesAmount; i++)
	{
		printf("%d |", i);
		for (int j = 0; j < graph->verticesAmount; j++)
		{
			float w = graph->edges[i][j];
			if (w > 0 && w < MAX_DISTANCE)
				printf("%.1f, ", w);
			else if (w == 0)
				printf(" * , ");
			else
				printf(" - , ");
		}
		printf("\n");
	}
}
