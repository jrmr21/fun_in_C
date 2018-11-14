#include "ft_header.h"

int		ft_rec(int nb, int power);

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (0);
	nb = ft_rec(nb, power);
	return (nb);
}

int		ft_rec(int nb, int power)
{
	if (power > 1)
		nb *= ft_rec(nb, --power);
	return (nb);
}
