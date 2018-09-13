/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:49:51 by cking             #+#    #+#             */
/*   Updated: 2018/09/13 14:26:29 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**Prints 'n' bits from index postion 'index' from memory stored in cw struct
*/

void	ft_print_bits(t_cw *cw, int index, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (cw->mem[index + i] < 16)
			ft_putchar('0');
		ft_putstr(ft_itoa_base(cw->mem[index + i], 16));
		i++;
		if (i <= n)
			ft_putchar(' ');

		if (i % 32 == 0)
			ft_putstr(": ");
		if (i % 32 == 0)
		{
			ft_putnbr(i/32);
			ft_putchar('\n');
		}
	}
	ft_putchar('\n');
}
