/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:12:12 by cking             #+#    #+#             */
/*   Updated: 2018/09/11 10:29:39 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_print_reg(t_pc *pc)
{
	int i;
	int j;

	i = 0;
	while (i < REG_NUMBER)
	{
		ft_putstr("Register ");
		ft_putnbr(i);
		ft_putstr(" :\t");
		j = 0;
		while (j < REG_SIZE)
		{
			if ((int)pc->registers[i][j])
			{
				if ((int)pc->registers[i][j] < 10)
					ft_putstr("00");
				else if ((int)pc->registers[i][j] < 100)
					ft_putstr("0");
				ft_putnbr((int)pc->registers[i][j]);
			}
			else
				ft_putstr("000");
			j++;
			ft_putchar(' ');
		}
		ft_putchar('\n');
		i++;
	}
}
