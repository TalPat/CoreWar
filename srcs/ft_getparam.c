/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getparam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 17:38:43 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/05 18:38:22 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

int	*ft_getparam(unsigned char c)
{
	int	*arr;
	int	i;

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
