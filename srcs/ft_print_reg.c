/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 10:12:12 by cking             #+#    #+#             */
/*   Updated: 2018/09/10 11:15:33 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_print_reg(t_pc *pc)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
	{
		ft_putstr("Register ");
		ft_putnbr(i);
		ft_putstr(" :\t");
		ft_putstr((char *)pc->registers[i]);
		ft_putchar('\n');
		i++;
	}
}
