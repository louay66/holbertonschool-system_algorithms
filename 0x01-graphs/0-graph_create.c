#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * graph_create - create new graph
 *
 * Return: pointer to new graph or NULL if error
 */
graph_t *graph_create(void)
{
	vertex_t *new_vertex;
	edge_t *new_edge;
	graph_t *new_graph;

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
	{
		return (NULL);
	}
	new_vertex = malloc(sizeof(vertex_t));
	if (!new_vertex)
	{
		free(new_edge);
		return (NULL);
	}
	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
	{
		free(new_edge);
		free(new_vertex);
		return (NULL);
	}

	/*--------init edges----------*/
	new_edge->dest = NULL;
	new_edge->next = NULL;
	/*--------init vertex----------*/
	new_vertex->index = 0;
	new_vertex->content = NULL;
	new_vertex->nb_edges = 0;
	new_vertex->edges = new_edge;
	new_vertex->next = NULL;
	/*--------init graph----------*/
	new_graph->nb_vertices = 0;
	new_graph->vertices = new_vertex;

	return (new_graph);
}
