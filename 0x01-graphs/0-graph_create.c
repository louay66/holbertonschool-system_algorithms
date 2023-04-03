#include <stdlib.h>
#include <stdio.h>

#include "graphs.h"

/**
 * graph_create - a function that allocates memory
 * to store a graph_t structure,
 * and initializes its content.
 * Return: A pointer to the allocated structure, or NULL on failure.
 */

graph_t *graph_create(void)
{
	graph_t *new = NULL;

	new = malloc(sizeof(graph_t));

	if (new == NULL)
		return (NULL);

	new->nb_vertices = 0;
	new->vertices = NULL;

	return (new);
}
