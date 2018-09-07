/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/07 12:42:06 by tpatter          ###   ########.fr       */
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
	pc->cr = 5;
	newidx = 0;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		newidx += 1;
		if (arr[1] == T_REG)
		{
			newidx += 1;
			while (i < REG_SIZE)
			{
				pc->registers[cw->mem[pc->index + 3]][i] =
					pc->registers[cw->mem[pc->index + 2]][i];
				i++;
			}
		}
		else
		{
			newidx += IND_SIZE;
			while (i < REG_SIZE)
			{
				cw->mem[pc->index + (ft_getdir(cw, pc->index + 3) % IDX_MOD)
				+ i] = pc->registers[cw->mem[pc->index + 2]][i];
				i++;
			}
		}
		pc->index += newidx + 1;
	}
	pc->index++;
}
