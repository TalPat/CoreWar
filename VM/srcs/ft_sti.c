/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:47:51 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 19:31:54 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
**using an indirect val as param 2 uses value at index(4 bytes).
*/

void	ft_param1(t_cw *cw, t_pc *pc, int *newidx, int *sum)
{
	int		*arr;

	arr = ft_getparam(cw->mem[pc->index + *newidx]);
	*newidx += 2;
	if (arr[1] == T_REG)
	{
		*sum = ft_getregval(pc, cw->mem[pc->index + *newidx]);
		*newidx += 1;
	}
	else if (arr[1] == T_DIR)
	{
		*sum = ft_getind(cw, pc->index + *newidx);
		*newidx += IND_SIZE;
	}
	else
	{
		*sum = ft_getdir(cw, (pc->index + ft_getind(cw, (pc->index +
			*newidx) % IDX_MOD)) % IDX_MOD);
		*newidx += IND_SIZE;
	}
}

void	ft_param2(t_cw *cw, t_pc *pc, int *newidx, int *sum)
{
	int	*arr;
	int	src;
	int i;

	i = 0;
	arr = ft_getparam(cw->mem[pc->index + *newidx]);
	if (arr[2] == T_REG)
	{
		*sum += ft_getregval(pc, cw->mem[pc->index + *newidx]);
		*newidx += 1;
	}
	else
	{
		*sum += ft_getind(cw, pc->index + *newidx);
		*newidx += IND_SIZE;
	}
	src = cw->mem[pc->index + 2];
	while (i < REG_SIZE)
	{
		cw->mem[(pc->index + (*sum % IDX_MOD) + i) % MEM_SIZE] =
			pc->registers[src - 1][i];
		cw->memp[(pc->index + (*sum % IDX_MOD) + i) % MEM_SIZE] =
			ft_abs((int)(pc->idnbr)) + 5; //added for viz
		i++;
	}
}

void	ft_sti(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		sum;

	if (!pc->cr)
		pc->cr = cw->op_tab[11].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 1;
		if (ft_verify_eb(cw, pc))
		{
			ft_param1(cw, pc, &newidx, &sum);
			ft_param2(cw, pc, &newidx, &sum);
		}
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
