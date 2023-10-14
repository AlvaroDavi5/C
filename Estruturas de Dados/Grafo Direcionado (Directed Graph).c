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

Graph *createGraph(unsigned int verticesAmount);
void destroyGraph(Graph *graph);
bool addEdge(Graph *graph, unsigned int src, unsigned int dest, float weight);
bool hasEdge(Graph *graph, unsigned int src, unsigned int dest);
void depthFirstSearch(Graph *graph, int srcVertex, unsigned int *visitedVertices);
void breadthFirstSearch(Graph *graph, int srcVertex, unsigned int *visitedVertices, int *verticesQueue);
void dijkstra(Graph *graph, int srcVertex, int destVertex);
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

	printf("\nDijkstra Algorithm:\n");
	dijkstra(graph, 0, 4);

	destroyGraph(graph);

	return 0;
}

Graph *createGraph(unsigned int verticesAmount)
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
				gr->edges[i][j] = 0.0; // distance from itself
			else
				gr->edges[i][j] = MAX_DISTANCE;
		}
	}

	return gr;
}

void destroyGraph(Graph *graph)
{
	if (graph->edges != NULL)
	{
		for (int i = 0; i < graph->verticesAmount; i++)
		{
			if (graph->edges[i] != NULL)
			{
				free(graph->edges[i]);
			}
		}

		free(graph->edges);
	}

	free(graph);
}

bool addEdge(Graph *graph, unsigned int src, unsigned int dest, float weight)
{
	if (hasEdge(graph, src, dest))
		return false;

	if (weight <= 0)
		weight = 1.0;

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

void depthFirstSearch(Graph *graph, int srcVertex, unsigned int *visitedVertices)
{
	if (graph == NULL || srcVertex < 0 || srcVertex >= graph->verticesAmount)
	{
		printf("Invalid input\n");
		return;
	}

	visitedVertices[srcVertex] = VISITED;
	printf("Visited vertex: %d\n", srcVertex);

	for (int i = 0; i < graph->verticesAmount; i++)
	{
		float w = graph->edges[srcVertex][i];
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
	visitedVertices[srcVertex] = FINISHED;
}

void breadthFirstSearch(Graph *graph, int srcVertex, unsigned int *visitedVertices, int *verticesQueue)
{
	if (graph == NULL || srcVertex < 0 || srcVertex >= graph->verticesAmount)
	{
		printf("Invalid input\n");
		return;
	}

	int front = 0;
	int rear = 0;

	verticesQueue[rear++] = srcVertex;
	visitedVertices[srcVertex] = VISITED;

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

int _minDistance(float *distanceFromSource, unsigned int *visitedVertices, const unsigned int verticesAmount)
{
	float min = MAX_DISTANCE;
	unsigned int minIndex = 0;

	for (int v = 0; v < verticesAmount; v++)
	{
		if (visitedVertices[v] < VISITED && distanceFromSource[v] <= min)
		{
			min = distanceFromSource[v];
			minIndex = v;
		}
	}

	return minIndex;
}

void dijkstra(Graph *graph, int srcVertex, int destVertex)
{
	const unsigned int verticesAmount = graph->verticesAmount;

	if (srcVertex < 0 || srcVertex >= verticesAmount || destVertex < 0 || destVertex >= verticesAmount)
	{
		printf("Invalid input\n");
		return;
	}

	float distanceFromSource[verticesAmount];
	unsigned int visitedVertices[verticesAmount];

	for (int i = 0; i < verticesAmount; i++)
	{
		distanceFromSource[i] = MAX_DISTANCE;
		visitedVertices[i] = UNKNOWN;
	}
	distanceFromSource[srcVertex] = 0.0; // distance from itself

	float **edgesArray = graph->edges;
	for (int j = 0; j < verticesAmount - 1; j++)
	{
		int u = _minDistance(distanceFromSource, visitedVertices, verticesAmount);
		visitedVertices[u] = VISITED;

		for (int v = 0; v < verticesAmount; v++)
		{
			float w = edgesArray[u][v];
			if (visitedVertices[v] < VISITED &&
					(w > 0 && w < MAX_DISTANCE) &&
					distanceFromSource[u] != MAX_DISTANCE &&
					(distanceFromSource[u] + w) < distanceFromSource[v])
			{
				distanceFromSource[v] = distanceFromSource[u] + w;
			}
		}
	}

	printf("Distance from [%d] to [%d]: %.5f\n", srcVertex, destVertex, distanceFromSource[destVertex]);
}

void displayGraphEdges(Graph *graph)
{
	float **edgesArray = graph->edges;
	for (int from = 0; from < graph->verticesAmount; from++)
	{
		for (int to = 0; to < graph->verticesAmount; to++)
		{
			float w = edgesArray[from][to];
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

	float **edgesArray = graph->edges;
	for (int i = 0; i < graph->verticesAmount; i++)
	{
		printf("%d |", i);
		for (int j = 0; j < graph->verticesAmount; j++)
		{
			float w = edgesArray[i][j];
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
