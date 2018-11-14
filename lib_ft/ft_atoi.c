#include "ft_header.h"

int		ft_atoi(char *str)
{
	int		i;
	char	out;
	int		sortie;

	i = 0;
	sortie = 0;
	out = 1;
	while (str[i] == '\n' || str[i] == '\r' || str[i] == '\v' ||
			str[i] == ' ' || str[i] == '\f' || str[i] == '\t')
		i++;
	if (str[i] == '-')
	{
		i++;
		out = -1;
	}
	else if (str[i] == '+')
		i++;
	while ((str[i] > 47) && (str[i] < 58))
	{
		sortie *= 10;
		sortie += (str[i] - 48);
		i++;
	}
	return (sortie * out);
}
