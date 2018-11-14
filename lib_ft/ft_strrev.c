#include "ft_header.h"

int		ft_strlen(char *str);

char	*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	*tempo;
	char	prout[*str];

	i = -1;
	size = ft_strlen(str);
	while (i++ <= size--)
	{
		prout[i] = str[size];
		prout[size] = str[i];
	}
	tempo = prout;
	return (tempo);
}
