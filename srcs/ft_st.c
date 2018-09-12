/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 18:57:14 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

void	ft_st(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		i;

	i = 0;
	if (!pc->cr)
		pc->cr = cw->op_tab[2].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 1;
		if (ft_verify_eb(cw, pc))
		{
			arr = ft_getparam(cw->mem[pc->index + newidx]);
			newidx += 2;
			if (arr[1] == T_REG)
			{
				while (i < REG_SIZE)
				{
					pc->registers[cw->mem[pc->index + 3]][i] =
						pc->registers[cw->mem[pc->index + 2]][i];
					i++;
				}
				newidx += 1;
			}
			else
			{
				while (i < REG_SIZE)
				{
					cw->mem[pc->index + (ft_getdir(cw, pc->index + 3) % IDX_MOD)
					+ i] = pc->registers[cw->mem[pc->index + 2]][i];
					i++;
				}
				newidx += IND_SIZE;
			}
		}
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
