#include "ft_header.h"

void	ft_swap(int *a, int *b)
{
	int tempo;

	tempo = *a;
	*a = *b;
	*b = tempo;
}
