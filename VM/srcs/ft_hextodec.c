/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:47:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 10:52:36 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int	ft_hextodec(char *str)
{
	int		val;
	int		charno;
	int		mult;

	charno = ft_strlen(str);
	val = 0;
	mult = 1;
	while (charno)
	{
		if (str[charno - 1] >= 'a' && str[charno - 1] <= 'f')
			val += (str[charno - 1] - 'a' + 10) * mult;
		if (str[charno - 1] >= '0' && str[charno - 1] <= '9')
			val += (str[charno - 1] - '0') * mult;
		mult *= 16;
		charno--;
	}
	return (val);
}
