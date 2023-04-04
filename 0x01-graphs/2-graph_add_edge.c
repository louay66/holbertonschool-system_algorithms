#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graphs.h"

/**
 * edge_check - checks if there is an edge between two vertices
 * @src: pointer to the source vertex
 * @dest: pointer to the destination vertex
 *
 * This function checks if there is an edge between the two given vertices
 * by iterating over the adjacency list of the source vertex and comparing
 * the destination vertex with each of its neighbors.
 *
 * Return: 1 if there is an edge from src to dest, 0 otherwise
 */
int edge_check(vertex_t *src, vertex_t *dest)
{
	edge_t *edge;

	if (!src || !dest)
		return (0);

	edge = src->edges;
	while (edge)
	{
		if (edge->dest == dest)
			return (1);
		edge = edge->next;
	}
	return (0);
}
/**
 * get_vertex - finds a vertex in a graph by its label
 * @graph: pointer to the graph structure
 * @s: string containing the label of the vertex to find
 *
 * This function searches for a vertex in the given graph that has the label
 * specified by the string argument
 * @s. If a matching vertex is found, a pointer
 * to it is returned. If no matching vertex is found, NULL is returned.
 *
 * Return: a pointer to the vertex with the given label, or NULL if not found
 */
vertex_t *get_vertex(graph_t *graph, const char *s)
{
	vertex_t *vertex;

	if (!graph || !s)
		return (NULL);
	vertex = graph->vertices;

	while (vertex)
	{
		if (!strcmp(vertex->content, s))
			return (vertex);
		vertex = vertex->next;
	}
	return (NULL);
}
/**
 * connect_vertex - creates a connection between two vertices in a graph
 * @src: pointer to the source vertex
 * @dest: pointer to the destination vertex
 *
 * This function creates a connection between the two given vertices in a graph
 * by adding the destination vertex to the adjacency list of the source vertex.
 * If either vertex is NULL, or if the destination vertex is already in the
 * adjacency list of the source vertex, the function returns -1 to indicate an
 * error. Otherwise, it returns 0 to indicate success.
 *
 * Return: 0 if the vertices were successfully connected, -1 otherwise
 */
int connect_vertex(vertex_t *src, vertex_t *dest)
{
	edge_t *new, *tmp;

	if (!src || !dest)
		return (0);

	tmp = src->edges;
	while (tmp && tmp->next)
	{
		tmp = tmp->next;
	}
	new = malloc(sizeof(*new));
	if (!new)
		return (0);
	new->dest = dest;
	new->next = NULL;
	if (!src->edges)
	{
		src->edges = new;
		src->nb_edges += 1;
		return (1);
	}
	else
	{
		tmp->next = new;
		src->nb_edges += 1;
		return (1);
	}

	return (0);
}
/**
 * graph_add_edge - adds an edge to a graph between two vertices
 * @graph: pointer to the graph structure
 * @src: string containing the label of the source vertex
 * @dest: string containing the label of the destination vertex
 * @type: type of the edge to add
 *
 * This function adds an edge to the given graph between the two vertices
 * specified by the source and destination labels in the @src and @dest
 * parameters, respectively. The type of the edge is specified by the @type
 * parameter, which should be one of the values in the edge_type_t enumeration.
 *
 * Return: 0 if the edge was successfully added to the graph, -1 otherwise
 */
int graph_add_edge(graph_t *graph, const char *src,
						 const char *dest, edge_type_t type)
{
	vertex_t *ver_src, *ver_dest;

	if (!graph || !src || !dest ||
		 (type != UNIDIRECTIONAL && type != BIDIRECTIONAL))
		return (0);
	ver_src = get_vertex(graph, src);
	ver_dest = get_vertex(graph, dest);
	if (type == BIDIRECTIONAL)
	{
		if (edge_check(ver_src, ver_dest) && edge_check(ver_dest, ver_src))
			return (1);
		if (!connect_vertex(ver_src, ver_dest))
			return (0);
		if (!connect_vertex(ver_dest, ver_src))
			return (0);
	}
	else
	{
		if (edge_check(ver_src, ver_dest))
			return (1);
		if (!connect_vertex(ver_src, ver_dest))
			return (0);
	}
	return (1);
}
