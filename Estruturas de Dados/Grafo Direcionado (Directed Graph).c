#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISTANCE 999999
#define isAValidWeight(w) (w > 0 && w < MAX_DISTANCE)

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
void depthFirstSearch(Graph *graph, int vertex, bool *visited);
void displayGraphEdges(Graph *graph);
void displayGraphTable(Graph *graph);

int main()
{
	Graph *graph = createGraph(5);

	addEdge(graph, 0, 1, 1.0);
	addEdge(graph, 0, 2, 2.0);
	addEdge(graph, 1, 3, 2.3);
	addEdge(graph, 2, 4, 2.0);
	addEdge(graph, 3, 4, 1.2);
	addEdge(graph, 4, 1, 3.1);
	addEdge(graph, 4, 0, 4.5);

	displayGraphTable(graph);
	displayGraphEdges(graph);

	bool visitedVertices[graph->verticesAmount];
	for (int i = 0; i < graph->verticesAmount; i++)
		visitedVertices[i] = false;

	depthFirstSearch(graph, 0, visitedVertices);

	destroyGraph(graph);

	return 0;
}

Graph *createGraph(int verticesAmount)
{
	Graph *gr = malloc(sizeof(Graph));
	if (gr == NULL)
	{
		printf("Error to allocate memory for graph");
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

void depthFirstSearch(Graph *graph, int vertex, bool *visited)
{
	visited[vertex] = true;
	printf("Visited vertex: %d\n", vertex);

	for (int i = 0; i < graph->verticesAmount; i++)
	{
		if (!visited[i] && isAValidWeight(graph->edges[vertex][i]))
		{
			depthFirstSearch(graph, i, visited);
		}
	}
}

void displayGraphEdges(Graph *graph)
{
	printf("Edges: {\n");
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
	printf("}\n");
}

void displayGraphTable(Graph *graph)
{
	printf("Table:\n");
	for (int i = 0; i < graph->verticesAmount; i++)
	{
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
