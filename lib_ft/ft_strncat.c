#include "ft_header.h"

char	*ft_strncat(char *dest, char *src, int nb)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[b] != '\0' && b < nb)
	{
		dest[i] = src[b];
		i++;
		b++;
	}
	dest[i] = '\0';
	return (dest);
}
