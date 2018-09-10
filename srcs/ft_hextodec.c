/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:47:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 17:18:09 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdio.h>

int	ft_hextodec(char *str)
{
	int		val;
	int		charno;
	int		mult;

	charno = ft_strlen(str) - 1;
	printf("len : %i\n", charno);
	val = 0;
	mult = 1;
	while (charno)
	{
		if (str[charno] >= 'a' && str[charno] <= 'f')
			val += (str[charno] - 'a' + 10) * mult;
		if (str[charno] >= '0' && str[charno] <= '9')
			val += (str[charno] - '0') * mult;
		mult *= 16;
		printf("ans : %i", val);
		charno--;
	}
	printf("ans : %i", val);
	return (val);
}
