/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:02:28 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 19:31:55 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

int		ft_streg(t_cw *cw, t_pc *pc)
{
	int	i;

	i = 0;
	while (i < REG_SIZE)
	{
		pc->registers[cw->mem[pc->index + 3] - 1][i] =
			pc->registers[cw->mem[pc->index + 2] - 1][i];
		i++;
	}
	return (1);
}

int		ft_stind(t_cw *cw, t_pc *pc)
{
	int	i;
	int	dest;
	int	src;

	i = 0;
	dest = ft_getind(cw, pc->index + 3);
	src = cw->mem[pc->index + 2];
	while (i < REG_SIZE)
	{
		cw->mem[(pc->index + (dest % IDX_MOD) + i) % MEM_SIZE] =
		pc->registers[src - 1][i];
		cw->memp[(pc->index + (dest % IDX_MOD) + i) % MEM_SIZE] = ft_abs((int)(pc->idnbr)) + 5; //added for viz
		i++;
	}
	return (IND_SIZE);
}

void	ft_st(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;

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
				newidx += ft_streg(cw, pc);
			else
				newidx += ft_stind(cw, pc);
		}
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
