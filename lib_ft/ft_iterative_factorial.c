#include "ft_header.h"

int		ft_iterative_factorial(int nb)
{
	int tempo;

	tempo = 1;
	if (nb == 1 || nb == 0)
		return (1);
	else if (nb > 12 || nb < 0)
		return (0);
	while (nb > 1)
	{
		tempo *= nb;
		nb--;
	}
	return (tempo);
}
