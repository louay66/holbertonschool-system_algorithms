#include "pathfinding.h"

/**
 * backtracking-  backtracking  algorithm
 * @map: 2-D read-only character map 1 blocked, 0 walkable
 * @rows: number of rows in map
 * @cols: number of cols in map
 * @target: target point
 * @x: x coordinate
 * @y: y coordinate
 * @visited: it is list of all cell i exploare it
 * Return: 1 on success, 0 on failure
 */
int backtracking(char **map, int rows, int cols,
					  point_t const *target, int x, int y, queue_t *visited)
{
	point_t *point;

	if (x < 0 || y < 0 || x >= rows || y >= cols || map[y][x] != '0')
		return (0);

	map[y][x] = '1';
	point = calloc(1, sizeof(*point));
	if (!point)
		exit(1);
	point->x = x;
	point->y = y;

	queue_push_front(visited, point);
	printf("Checking coordinates [%d, %d]\n", x, y);
	if (x == target->x && y == target->y)
		return (1);
	if (backtracking(map, rows, cols, target, x + 1, y, visited) ||
		 backtracking(map, rows, cols, target, x, y + 1, visited) ||
		 backtracking(map, rows, cols, target, x - 1, y, visited) ||
		 backtracking(map, rows, cols, target, x, y - 1, visited))
		return (1);
	free(dequeue(visited));

	return (0);
}

/**
 * backtracking_array - it use backtracking  algorithm to find path
 * @map: 2-D read-only character map 1 blocked, 0 walkable
 * @rows: number of rows in map
 * @cols: number of cols in map
 * @start: starting point
 * @target: target point
 * Return: queue containing path of points
 */
queue_t *backtracking_array(char **map, int rows, int cols,
									 point_t const *start, point_t const *target)
{
	queue_t *path, *visited;
	point_t *curent_point;
	char **mapToWrite;
	int i;

	path = queue_create();
	visited = queue_create();
	if (!path || !visited)
		exit(1);
	mapToWrite = malloc(rows * sizeof(char *));
	if (!mapToWrite)
		exit(1);
	for (i = 0; i < rows; i++)
	{
		mapToWrite[i] = malloc(cols + 1);
		if (!mapToWrite[i])
			return (NULL);
		strcpy(mapToWrite[i], map[i]);
	}

	if (backtracking(mapToWrite, rows, cols, target, start->x, start->y, visited))
	{
		while ((curent_point = dequeue(visited)))
		{
			queue_push_front(path, curent_point);
		}
		free(visited);
	}
	else
	{
		free(path);
		free(visited);
		path = NULL;
	}
	for (i = 0; i < rows; i++)
	{
		free(mapToWrite[i]);
	}
	free(mapToWrite);
	return (path);
}
