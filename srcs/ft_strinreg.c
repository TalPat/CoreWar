/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinreg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 19:11:52 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 19:38:48 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include <stdlib.h>

void	ft_strinreg(t_pc *pc, int regno, int val)
{
	int	i;
	int	newval;
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
