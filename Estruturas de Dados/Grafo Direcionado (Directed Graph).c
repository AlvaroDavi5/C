#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>


#define FALSE 0
#define TRUE 1


struct graph
{
	int num_nodes;
	bool **edges;
};
typedef struct graph Graph;


Graph * createGraph(int num_nodes);
void destroyGraph(Graph *graph);
bool addEdge(Graph *graph, unsigned int from_node, unsigned int to_node);
bool hasEdge(Graph *graph, unsigned int from_node, unsigned int to_node);
void displayGraph(Graph *graph);


int main()
{
	Graph *g = createGraph(5);

	addEdge(g, 0, 1);
	addEdge(g, 0, 2);
	addEdge(g, 1, 3);
	addEdge(g, 3, 4);
	addEdge(g, 4, 1);
	addEdge(g, 4, 0);

	displayGraph(g);

	destroyGraph(g);

	return 0;
}


Graph * createGraph(int num_nodes)
{
	Graph *gr = malloc(sizeof(Graph));
	if (gr == NULL)
	{
		printf("Error to allocate memory for graph");
		return NULL;
	}

	gr->num_nodes = num_nodes;
	gr->edges = calloc(sizeof(bool *), gr->num_nodes);
	if (gr->edges == NULL)
	{
		free(gr);
		return NULL;
	}

	for (int i = 0; i < gr->num_nodes; i++)
	{
		(gr->edges[i]) = calloc(sizeof(bool), gr->num_nodes);
		if (gr->edges[i] == NULL)
		{
			destroyGraph(gr);
			return NULL;
		}
	}

	return gr;
}

void destroyGraph(Graph *graph)
{
	if (graph->edges == NULL)
	{
		return;
	}

	for (int i = 0; i < graph->num_nodes; i++)
	{
		if (graph->edges[i] != NULL)
		{
			free(graph->edges[i]);
		}
	}
	free(graph->edges);
}

bool addEdge(Graph *graph, unsigned int from_node, unsigned int to_node)
{
	if (hasEdge(graph, from_node, to_node))
		return FALSE;

	graph->edges[from_node][to_node] = true;

	return TRUE;
}

bool hasEdge(Graph *graph, unsigned int from_node, unsigned int to_node)
{
	assert(graph != NULL);
	assert(from_node < graph->num_nodes);
	assert(to_node < graph->num_nodes);

	return graph->edges[from_node][to_node];
}

void displayGraph(Graph *graph)
{
	printf("Digraph: {\n");
	for (int from = 0; from < graph->num_nodes; from++)
	{
		for (int to = 0; to < graph->num_nodes; to++)
		{
			if ((graph->edges)[from][to])
			{
				printf("%d -> %d;\n", from, to);
			}
		}
	}
	printf("}\n");
}

