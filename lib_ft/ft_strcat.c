#include "ft_header.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int b;

	b = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[b] != '\0')
	{
		dest[i] = src[b];
		i++;
		b++;
	}
	dest[i] = '\0';
	return (dest);
}
