#include "ft_header.h"

void	ft_sort_integer_table(int *tab, int size)
{
	int cpt;
	int i;
	int test;

	cpt = -1;
	while (++cpt < size)
	{
		i = -1;
		while (++i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				test = tab[i + 1];
				tab[i + 1] = tab[i];
				tab[i] = test;
			}
		}
	}
}
