/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:49:51 by cking             #+#    #+#             */
/*   Updated: 2018/09/13 15:44:52 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**Prints 'n' bits from index postion 'index' from memory stored in cw struct
*/

void	ft_print_bits(t_cw *cw, int index, int n)
{
	int	i;
	unsigned char	*temp;

	i = 0;
	while (i < n)
	{
		temp = &cw->mem[index + i];
		if (i % 32 == 0)
		{
			ft_putstr("0x");
			if (index + i < 4096)
				ft_putchar('0');
			if (index + i < 256)
				ft_putchar('0');
			if (!(index + i))
				ft_putchar('0');
			ft_putstr(ft_itoa_base((index + i), 16));
			ft_putstr(" : ");
		}
		if (cw->mem[index + i] < 16)
			ft_putchar('_');
		if(cw->mem[index + i], 16))
			ft_putstr(ft_itoa_base(cw->mem[index + i], 16));
		else
			ft_putchar('_');
		i++;
		if (i <= n)
			ft_putchar(' ');
		if (i % 32 == 0)
			ft_putchar('\n');
	}
	ft_putchar('\n');
}
