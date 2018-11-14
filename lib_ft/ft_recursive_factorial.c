#include "ft_header.h"

int		ft(int nb, int cpt);

int		ft_recursive_factorial(int nb)
{
	int c;

	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 0 | nb == 1)
		return (1);
	c = 1;
	nb = ft(c, nb);
	return (nb);
}

int		ft(int nb, int cpt)
{
	if (cpt > 1)
		return (ft((nb * cpt), (cpt - 1)));
	else
		return (nb);
}
