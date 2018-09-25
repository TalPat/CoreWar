/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:49:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 16:15:08 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/asm.h"
#include <stdlib.h>
#include <unistd.h>

int		ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	return (0);
}

int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

int	ft_isalpha(int c)
{
	if (ft_isupper(c) || ft_islower(c))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	ft_strlen(const char *s)
{
	int i;

	i = -1;
	while (*(s + ++i))
		;
	return (i);
}

int		ft_wcount(const char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (*(str + i))
	{
		while (*(str + i) == c)
			i++;
		if (*(str + i) != c && *(str + i))
			count++;
		while (*(str + i) != c && *(str + i))
			i++;
	}
	return (count);
}

int		spacecount(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(ft_isspace(str[i]))
			count++;
		i++;
	}
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int index;

	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar(str[index]);
		index++;
	}
}



char	*trim(char *str)
{
	int		newlen;
	char	*out;
	int		i; //incrementor in new string
	int		j; //incrementor in old string
	int		wcount;

	newlen = ft_strlen(str) - (spacecount(str) - (ft_wcount(str, ' ') - 1)) + 1;
	out = (char *)malloc(sizeof(char) * newlen);
	i = 0;
	j = 0;
	wcount = ft_wcount(str, ' ');
	while (wcount)
	{
		while(ft_isspace(str[i]))
			i++;
		while(ft_isalnum(str[i]))
		{
			out[j] = str[i];
			i++;
			j++;
		}
		wcount--;
		while(ft_isspace(str[i]))
			i++;
		out[j] = ' ';
		j++;
	}
}

int		main(int ac, char **av)
{	
	char *str = "   test  test  \ntest";
	char *out = trim(str);
	ft_putstr(out);
	ft_putchar('\n');
}
