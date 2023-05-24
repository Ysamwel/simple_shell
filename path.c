#include "main.h"
#include "extern.h"

/**
 * add_path - Adds a new path to the path list
 * @head: Head of the path list
 * @path: Path to add
 * Return: Updated head of the path list
 */
PathNode *add_path(PathNode *head, const char *path)
{
	PathNode *newNode;
	PathNode *current;

	newNode = malloc(sizeof(PathNode));
	if (newNode == NULL)
	{
		perror("malloc");
		exit(1);
	}

	strcpy(newNode->path, path);
	newNode->next = NULL;

	if (head == NULL)
		return (newNode);

	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
	return (head);
}

/**
 * tokenize_path - Tokenizes the path string into individual paths
 * @path: Path string to tokenize
 * Return: Head of the path list
 */
PathNode *tokenize_path(const char *path)
{
	PathNode *pathList = NULL;
	char *token;

	token = _strtok((char *)path, ":");
	while (token != NULL)
	{
		pathList = add_path(pathList, token);
		token = _strtok(NULL, ":");
	}

	return (pathList);
}

/**
 * free_paths - Frees the memory allocated for the path list
 * @head: Head of the path list
 */
void free_paths(PathNode *head)
{
	PathNode *current = head;

	while (current != NULL)
	{
		PathNode *next = current->next;

		free(current);
		current = next;
	}
}

PathNode *get_search_path(void)
{
	PathNode *pathList;
	char *path;
	char *dir;

	path = _getenviron("PATH", environ);
	pathList = NULL;

	if (path != NULL)
	{
		dir = _strtok(path, ":");
		while (dir != NULL)
		{
			pathList = add_path(pathList, dir);
			dir = _strtok(NULL, ":");
		}
	}

	return (pathList);
}
