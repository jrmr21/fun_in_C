#include "ft_header.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int cpt;

	cpt = 0;
	while (*s1 == *s2 && *s1 != '\0' && cpt < n - 1)
	{
		s2 += 1;
		s1 += 1;
		cpt++;
	}
	return (*s1 - *s2);
}
