#include "cw.h"

int		ft_numlen(int value, int base)
{
	int				i;
	int				nbr;
	unsigned int	n;

	i = 0;
	nbr = value;
	if (nbr < 0 && base != 10)
	{
		n = (unsigned int)nbr;
		while (n)
		{
			i++;
			n /= base;
		}
		return (i);
	}
	if ((nbr < 0 && base == 10) || nbr == 0)
		i++;
	while (nbr)
	{
		i++;
		nbr /= base;
	}
	return (i);
}

char	*ft_itoa_base(int value, int base)
{
	char			*str;
	char			*num;
	char			c;
	int				i;
	int				nbr;
	unsigned int	n;

	str = "0123456789ABCDEF";
	i = ft_numlen(value, base) - 1;
	nbr = value;
	if (!(num = (char*)malloc(sizeof(char) * (i + 2))))
		return (0);
	if (value == -2147483648 && base == 10)
	{
		str = "-2147483648";
		return (str);
	}
	if (nbr == 0)
	{
		num[i] = '0';
		num[i + 1] = '\0';
		return (num);
	}
	if (base == 10 && nbr < 0)
	{
		num[0] = '-';
		nbr = -nbr;
	}
	if (nbr < 0 && base != 10)
	{
		n = (unsigned int)nbr;
		while (n)
		{
			c = str[n % base];
			num[i] = c;
			n /= base;
			i--;
		}
		num[ft_numlen(value, base)] = '\0';
		return (num);
	}
	while (nbr)
	{
		c = str[nbr % base];
		num[i] = c;
		nbr /= base;
		i--;
	}
	num[ft_numlen(value, base)] = '\0';
	return (num);
}