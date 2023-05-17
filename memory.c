#include "main.h"
void _memcpy(void *aftptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_aftptr = (char *)aftptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_aftptr[i] = char_ptr[i]
void *_realloc(void *ptr, unsigned int prev_size, unsigned int aft_size)
{
	void *aftptr;

	if (ptr == NULL)
		return (malloc(aft_size));

	if (aft_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (aft_size == prev_size)
		return (ptr);

	aftptr = malloc(aft_size);
	if (aftptr == NULL)
		return (NULL);

	if (aft_size < prev_size)
		_memcpy(aftptr, ptr, prev_size);
	else
		_memcpy(aftptr, ptr, prev_size);

	free(ptr);
	return (aftptr);
}


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
