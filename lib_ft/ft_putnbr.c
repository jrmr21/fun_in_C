#include "ft_header.h"

int		ft_putchar(char c);

void	ft_putnbr(int nb)
{
	unsigned int tempo;

	if (nb < 0)
	{
		tempo = nb * -1;
		ft_putchar('-');
	}
	else
		tempo = nb;
	if (tempo > 9)
	{
		ft_putnbr(tempo / 10);
		ft_putchar((tempo % 10) + 48);
	}
	else
	{
		ft_putchar(tempo + 48);
		return ;
	}
}
