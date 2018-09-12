/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:47:51 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 15:40:35 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
**using an indirect val as param 2 uses value at index(4 bytes).
*/

void	ft_sti(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		i;
	int		sum;

	i = 0;
	pc->cr = cw->op_tab[11].ctc;
	newidx = 1;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + newidx]);
		newidx += 2;
		if (arr[1] == T_REG)
		{
			sum = ft_getregval(pc, cw->mem[pc->index + newidx]);
			newidx += 1;
		}
		else if (arr[1] == T_IND)
		{
			sum = ft_getdir(cw, pc->index + newidx);
			newidx += DIR_SIZE;
		}
		else
		{
			sum = ft_getdir(cw, (pc->index + ft_getind(cw, (pc->index +
				newidx) % IDX_MOD)) % IDX_MOD);
			newidx += IND_SIZE;
		}
		if (arr[2] == T_REG)
		{
			sum += ft_getregval(pc, cw->mem[pc->index + newidx]);
			newidx += 1;
		}
		else
		{
			sum += ft_getdir(cw, pc->index + newidx);
			newidx += DIR_SIZE;
		}
		while (i < REG_SIZE)
		{
			cw->mem[pc->index + (sum % IDX_MOD) + i] =
				pc->registers[cw->mem[pc->index + 2]][i];
			i++;
		}
	}
	pc->index += newidx;
}
