#include "embed_malloc.h"

uint8_t	add_element(tab_s * tab, int size)
{
	tab_s	* tempo;
	tab_s	* new_case;

	tempo		= tab;

	for (int i = 0; i < size; i++)
	{
		new_case = NULL;

		if (tempo->next == NULL)
			new_case = malloc (sizeof(tab_s *));
		else
			return (1);	// error

		if (NULL == new_case)
			return (1);	// return error
		else
		{
			tempo->next	= new_case;

			tempo 		= new_case;
			tempo->next	= NULL;
			tempo->data	= 0;
		}
		//printf("\ncase %d: %p", i, tempo);
	}
	return (0);
}

uint8_t	setValue_element(tab_s * tab, int bloc, uint8_t playLoad)
{
	tab_s * tempo = tab;

	for (int i = 0; i < bloc; i++)
	{
		//printf("case %d: %p\n", i, tempo);
		if (tempo->next != NULL)
			tempo = tempo->next;
		else
			return (1);	// return error
	}
	tempo->data = playLoad;
	return (0);
}

uint8_t getValue_element(tab_s * tab, int bloc)
{
	tab_s * tempo = tab;

	for (int i = 0; i < bloc; i++)
	{
		if (tempo->next != NULL)
			tempo = tempo->next;
		else
			return (1);	// return error
	}
	return (tempo->data);
}

int     sizeof_element(tab_s * tab)
{
	tab_s	* 	tempo;
	int		i;

	i	= 0;
	tempo	= tab;

	if (tempo == NULL)
		return (1);	// error

	while (tempo->next != NULL)
	{
		++i;
		tempo = tempo->next;
	}
	return (i);
}


void    show_element(tab_s * tab)
{
	tab_s	*	tempo;
	int		i;

	i	= 0;
	tempo	= tab;
	while (tempo->next != NULL)
	{
		printf("id: %p , case: %d , data: %d \n", tempo, i, tempo->data);
		++i;
		tempo = tempo->next;
	}
}

uint8_t clearAll_element(tab_s * tab)
{
	tab_s	* tempo;
	tab_s	* tempo_Delete;

	tempo = tab;
	int i = 0;
	
	while (tempo->next != NULL)
	{
		tempo_Delete	= tempo;
		tempo		= tempo->next;

		free(tempo_Delete->next);
		++i;
	}
	free (tempo->next);
	return (0);
}
