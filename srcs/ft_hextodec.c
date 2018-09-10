/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextodec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:47:19 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 16:58:37 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

int	ft_hextodec(char *str)
{
	int		val;
	int		charno;
	int		mult;

	charno = ft_strlen(str) - 1;
	val = 0;
	mult = 1;
	while (charno)
	{
		if (str[charno] >= 'a' && str[charno] <= 'f')
			val += (str[charno] - 'a' + 10) * mult;
		if (str[charno] >= '0' && str[charno] <= '9')
			val += (str[charno] - '0') * mult;
		mult *= 16;
		charno--;
	}
	return (val);
}
