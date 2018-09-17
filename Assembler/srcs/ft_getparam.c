/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:38:43 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 10:28:48 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"
#include "../includes/cw.h"

int		*ft_getparam(unsigned char c)
{
	int		*arr;
	int		i;

	i = 4;
	arr = (int*)malloc(sizeof(int) * 4);
	while (i)
	{
		if (c % 4 == 1)
			arr[i - 1] = 1;
		else if (c % 4 == 2)
			arr[i - 1] = 2;
		else if (c % 4 == 3)
			arr[i - 1] = 4;
		else
			arr[i - 1] = 0;
		c = c / 4;
		i--;
	}
	return (arr);
}
/*
** returns an array similar to ft_getparam but instead of indetifiers it returns an
** array of interger sizes of the parameters encoded by the encoding byte.
*/

int		*ft_getparam_size(unsigned char c)
{
	int		*arr;
	int		i;

	arr = ft_getparam(c);
	i = 4;
	while (i)
	{
		if (arr[i - 1] == T_DIR)
			arr[i - 1] = DIR_SIZE;
		else if (arr[i - 1] == T_IND)
			arr[i - 1] = IND_SIZE;
		else if (arr[i - 1] == T_REG)
			arr[i - 1] = REG_SIZE;
		else
			arr[i - 1] = 0;
		i--;
	}
	return (arr);
}
