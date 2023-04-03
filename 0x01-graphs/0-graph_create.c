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
	graph_t *new_graph = NULL;

	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
	{
		return (NULL);
	}
	/*--------init graph----------*/
	new_graph->nb_vertices = 0;
	new_graph->vertices = NULL;

	return (new_grasdv, ph);
}
