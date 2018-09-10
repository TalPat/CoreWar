/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:47:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 17:27:27 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdio.h>

int	ft_hextodec(char *str)
{
	int		val;
	int		charno;
	int		mult;

	charno = ft_strlen(str);
	printf("len : %i\n", charno);
	val = 0;
	mult = 1;
	while (charno)
	{
		if (str[charno - 1] >= 'a' && str[charno - 1] <= 'f')
			val += (str[charno - 1] - 'a' + 10) * mult;
		if (str[charno - 1] >= '0' && str[charno - 1] <= '9')
			val += (str[charno - 1] - '0') * mult;
		mult *= 16;
		printf("ans : %i", val);
		charno--;
	}
	printf("ans : %i", val);
	return (val);
}
