/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:12:07 by cking             #+#    #+#             */
/*   Updated: 2018/09/07 13:36:02 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	print_bits(t_cw *cw, int index, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putstr(ft_itoa_base(cw->mem[i], 16));
		ft_puchar(' ');
		i++;
	}
}
