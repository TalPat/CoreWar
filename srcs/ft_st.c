/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 18:33:11 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

void	ft_st(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		storeidx;
	int		i;

	i = 0;
	pc->cr = cw->op_tab[2].ctc;
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
	pc->index += newidx;
}
