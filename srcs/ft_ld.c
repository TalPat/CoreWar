/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:10:31 by cking             #+#    #+#             */
/*   Updated: 2018/09/07 13:10:08 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void		ft_ld(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		i;

	pc->cr = 5;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		if (arr[0] == T_DIR)
		{
			ft_memcpy(pc->registers[cw->mem[pc->index + 2 + DIR_SIZE]],
			cw->mem[pc->index + 2], DIR_SIZE);
			pc->index = pc->index + 2 + DIR_SIZE;
		}
		else
		{
			i = -1;
			while (++i < REG_SIZE)
				cw->mem[pc->index + (ft_getind(cw, pc->index + 2 + IND_SIZE))
				+ i] = pc->registers[cw->mem[pc->index + 2 + IND_SIZE]];
			pc->index = pc->index + 2 + IND_SIZE;
		}
	}
	else
		pc->index += 2;
}

int		main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 2;
	cw->mem[1] = 144;
	cw->mem[2] = 0;
	cw->mem[3] = 0;
	cw->mem[4] = 0;
	cw->mem[5] = 'B';
	cw->mem[6] = 2;
	pc->index = 0;
	pc->registers[0] = 0;
	pc->registers[1] = 0;
	pc->registers[2] = 0;
	pc->registers[3] = 0;
	ft_ld(cw, pc);
	ft_putnbr(pc->registers[2]);
}
