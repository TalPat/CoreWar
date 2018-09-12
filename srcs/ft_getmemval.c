/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmemval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:32:45 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 09:55:12 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
** Takes a corewar object, an index position inside the cw object and a size
** of the memory that should be parsed for it's value. It returns the value
** for that given size at the given index as an integer value
*/

int		ft_getmemval(t_cw *cw, int index, int size)
{
	int	val;
	int	mult;

	val = 0;
	mult = 1;
	while (size >= 0)
	{
		val = val + (cw->mem[index + size - 1] * mult);
		mult *= 256;
		size--;
	}
	return (val);
}

// int		main(void)
// {
// 	t_cw			*cw;

// 	cw = (t_cw *)malloc(sizeof(t_cw));
// 	ft_inittable(cw);
// 	cw->mem = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
// 	ft_bzero(cw->mem, MEM_SIZE);
// 	cw->mem[0] = 0;
// 	cw->mem[1] = 0;
// 	cw->mem[2] = 0;
// 	cw->mem[3] = 0;
// 	cw->mem[4] = 0;
// 	cw->mem[5] = 1;
// 	cw->mem[6] = 0;
// 	ft_print_bits(cw, 0, 7);
// 	ft_putnbr(ft_getmemval(cw, 0, 7));
// }
