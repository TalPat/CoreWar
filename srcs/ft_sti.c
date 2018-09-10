/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:47:51 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 16:04:47 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
**using an indirect val as param 2 not accounted for? pdf does not specify its
**use.
*/

void	ft_sti(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		storeidx;
	int		i;
	int		sum;

	i = 0;
	pc->cr = cw->op_tab[11].ctc;
	newidx = 0;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		newidx += 1;
		if (arr[1] == T_REG)
		{
			newidx += 1;
			sum = ft_getregval(pc, cw->mem[pc->index + 2]);
		}
		else
		{
			newidx += DIR_SIZE;
			sum = ft_getdir(cw, pc->index + 2);
		}
		if (arr[2] == T_REG)
		{
			newidx += 1;
			sum += ft_getregval(pc, cw->mem[pc->index + newidx]);
		}
		else
		{
			newidx += DIR_SIZE;
			sum += ft_getdir(cw, pc->index + newidx);
		}
		while (i < REG_SIZE)
		{
			cw->mem[pc->index + (sum % IDX_MOD) + i] =
				pc->registers[cw->mem[pc->index + 2]][i];
			i++;
		}
		pc->index += newidx + 1;
	}
	pc->index++;
}
