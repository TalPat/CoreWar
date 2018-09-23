/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:49:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/17 15:26:19 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		spacecount(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while(str[i])
	{
		if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

char	*trim(char *str)
{
	int		newlen;
	char	*out;
	int		i; //incrementor in new string
	int		j; //incrementor in old string
	int		wcount;

	newlen = ft_strlen(str) - (spacecount(str) - (ft_wcount(str) - 1)) + 1;
	out = (char *)malloc(sizeof(char) * newlen);
	i = 0;
	j = 0;
	wcount = ft_wcount(str);
}

int	main(int ac, char **av)
{
	char *str = "   test  test  \ntest";
	char *trim = ft_strtrim(str);
	ft_putstr(trim);
}