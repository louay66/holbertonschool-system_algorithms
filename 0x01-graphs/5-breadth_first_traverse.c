#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "graphs.h"

static size_t *visted;

/**
 * free_queue - free a queue
 * @queue: queue to free
 * Return: queue
 */
void free_queue(queue_t *queue)
{
	node_t *node, *tmpnode;

	node = queue->head;
	while (node)
	{
		tmpnode = node;
		node = node->next;
		free(tmpnode);
	}
	free(queue);
}
/**
 * push - push new vertex to the queue
 * @queue: queue to free
 * @vertex: vertex to push
 * @depth: depth of search
 * Return: 1 if successful otherwise 0
 */
int push(queue_t *queue, vertex_t *vertex, size_t depth)
{
	node_t *node;

	node = calloc(1, sizeof(node_t));
	if (!node)
	{
		free_queue(queue);
		free(visted);
		return (0);
	}
	node->vertex = vertex;
	node->depth = depth;
	if (!queue->tail)
	{
		queue->tail = queue->head = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
	queue->size++;
	return (1);
}
/**
 * pop - pop node  from the queue
 * @queue: queue to free
 * @vertex: vertex to hold the node poped
 * @depth: to hold depth of node
 * Return: 1 if successful otherwise 0
 */
int pop(queue_t *queue, vertex_t **vertex, size_t *depth)
{
	node_t *node;

	if (!queue || !queue->head)
		return (0);
	node = queue->head;
	queue->head = queue->head->next;
	if (!queue->head)
		queue->tail = NULL;
	*vertex = node->vertex;
	queue->size--;
	*depth = node->depth;
	free(node);
	return (1);
}
/**
 * breadth_first_traverse -breadth first traverse
 * @graph: pointer to graph object
 * @action:  pointer to traverse function
 * Return: max depth of traversal
 */
size_t breadth_first_traverse(const graph_t *graph,
		void (*action)(const vertex_t *v, size_t depth))
{
	queue_t *queue;
	vertex_t *node_vertex;
	edge_t *edge;
	size_t max_depth = 0, node_depth, i, sz;

	if (!graph || !action || !graph->nb_vertices)
		return (0);
	visted = calloc(graph->nb_vertices, sizeof(size_t));
	if (!visted)
		return (0);
	queue = calloc(1, sizeof(queue_t));
	if (!queue)
		return (free(visted), 0);
	visted[graph->vertices->index] = 1;
	push(queue, graph->vertices, 0);
	while (queue->size)
	{
		for (i = 0, sz = queue->size; i < sz; i++)
		{
			pop(queue, &node_vertex, &node_depth);
			action(node_vertex, node_depth);
			max_depth = max_depth > node_depth ? max_depth : node_depth;
			for (edge = node_vertex->edges; edge; edge = edge->next)
			{
				if (visted[edge->dest->index])
					continue;
				visted[edge->dest->index] = 1;
				if (!push(queue, edge->dest, node_depth + 1))
					return (0);
			}
		}
	}
	free(visted);
	free_queue(queue);
	return (max_depth);
}
