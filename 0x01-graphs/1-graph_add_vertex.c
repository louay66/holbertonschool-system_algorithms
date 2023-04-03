#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graphs.h"

/**
 * graph_add_vertex - Adds a vertex to the graph
 * @graph: Pointer to the graph
 * @str: String content of the vertex to be added
 * Return: Pointer to the newly added vertex or NULL on failure
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *new_vertex = NULL, *tmp = NULL;

	if (!str || !graph)
		return (NULL);
	tmp = graph->vertices;
	while (tmp)
	{
		if (!strcmp(tmp->content, str))
			return (NULL);
		if (!tmp->next)
			break;
		tmp = tmp->next;
	}
	new_vertex = malloc(sizeof(*tmp));
	if (!new_vertex)
		return (NULL);

	/*--------init vertex----------*/
	new_vertex->content = strdup(str);
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;
	if (!graph->vertices)
	{
		new_vertex->index = 0;
		graph->vertices = new_vertex;
	}
	else
	{
		new_vertex->index = tmp->index + 1;
		tmp->next = new_vertex;
	}
	graph->nb_vertices++;
	return (new_vertex);
}
