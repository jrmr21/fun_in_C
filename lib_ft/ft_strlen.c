#include "ft_header.h"

int		ft_strlen(char *str)
{
	int out;

	out = 0;
	while (*str++)
		out++;
	return (out);
}
