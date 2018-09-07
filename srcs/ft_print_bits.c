/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 15:49:51 by cking             #+#    #+#             */
/*   Updated: 2018/09/07 16:08:20 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_print_bits(t_cw *cw, int index, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putstr(ft_itoa_base(cw->mem[index + i], 16));
		ft_putchar(' ');
		i++;
	}
}
