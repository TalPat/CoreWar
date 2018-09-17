/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinreg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:11:52 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 15:56:40 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include <stdlib.h>

void	ft_strinreg(t_pc *pc, int regno, int val)
{
	int	i;
	int mult;

	mult = 1;
	val = 0;
	i = 0;
	if (regno < 1 || regno > REG_NUMBER)
		return ;
	while (val && i < REG_SIZE)
	{
		pc->registers[regno][REG_SIZE - i - 1] = val % 16;
		val = val / 16;
		i++;
	}
}
