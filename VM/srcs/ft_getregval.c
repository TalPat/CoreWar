/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getregval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 15:48:14 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 16:44:21 by jde-agr          ###   ########.fr       */
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

	if (reg < 0 || reg >= REG_NUMBER)
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
