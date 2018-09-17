/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getregval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:48:14 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 10:51:37 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**Returns integer value of bytes held within a referenced register
*/

int	ft_getregval(t_pc *pc, int reg)
{
	int	i;
	int	val;
	int	mult;

	if (reg < 1 || reg > REG_NUMBER)
		return (0);
	i = 0;
	val = 0;
	mult = 1;
	while (i < REG_SIZE)
	{
		val = val + (pc->registers[reg][REG_SIZE - i - 1] * mult);
		mult *= 256;
		i++;
	}
	return (val);
}
