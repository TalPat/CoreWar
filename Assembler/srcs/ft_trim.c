/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/25 14:23:24 by cking             #+#    #+#             */
/*   Updated: 2018/09/25 14:23:24 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

char	*ft_trim(char *str)
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
			printf("str[%d]:%c\n", i, str[i]);
			i++;
			j++;
		}
		wcount--;
		while(ft_isspace(str[i]))
			i++;
		if (wcount)
			out[j++] = ' ';
	}
	out[j] = '\0';
	return (out);
}