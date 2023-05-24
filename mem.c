#include "main.h"

/**
 * _memcpy - Copies memory
 * @aftptr: Pointer to the destination memory
 * @ptr: Pointer to the source memory
 * @size: Size of the memory to copy
 * Return: void
 */
void _memcpy(void *aftptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_aftptr = (char *)aftptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_aftptr[i] = char_ptr[i];
}

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: Pointer to the previously allocated memory
 * @size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 */
void *_realloc(void *ptr, size_t size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(size);
	if (newptr == NULL)
		return (NULL);

	_memcpy(newptr, ptr, size);
	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - Reallocates memory for a double pointer
 * @ptr: Double pointer to the memory to reallocate
 * @prev_size: Previous size of the memory
 * @aft_size: New size of the memory
 * Return: Double pointer to the reallocated memory
 */
char **_reallocdp(char **ptr, unsigned int prev_size, unsigned int aft_size)
{
	char **aftptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * aft_size));

	if (aft_size == prev_size)
		return (ptr);

	aftptr = malloc(sizeof(char *) * aft_size);
	if (aftptr == NULL)
		return (NULL);

	for (i = 0; i < prev_size; i++)
		aftptr[i] = ptr[i];

	free(ptr);

	return (aftptr);
}
