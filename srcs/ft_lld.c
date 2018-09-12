/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lld.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 16:03:07 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 10:10:19 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void		ft_llddir(t_cw *cw, t_pc *pc)
{
	int i;
	int regnum;
	int check;

	i = 0;
	regnum = cw->mem[pc->index + 2 + DIR_SIZE];
	while (i < REG_SIZE)
	{
		pc->registers[regnum][i] = cw->mem[pc->index + 2 + i];
		if (cw->mem[pc->index + 2 + i])
			check++;
		i++;
	}
	pc->index = pc->index + 2 + DIR_SIZE;
	if (!check)
		pc->carry = '1';
	else
		pc->carry = NULL;
}

void		ft_lldind(t_cw *cw, t_pc *pc)
{
	int regnum;
	int i;
	int offset;
	int check;

	regnum = cw->mem[pc->index + 2 + IND_SIZE];
	i = 0;
	offset = ft_hextodec(ft_strsub((char *)cw->mem, pc->index + 2, IND_SIZE));
	while (i < REG_SIZE)
	{
		pc->registers[regnum][i] = cw->mem[pc->index + i + (offset % IDX_MOD)];
		if (cw->mem[pc->index + i + (offset % IDX_MOD)])
			check++;
		i++;
		if (!check)
			pc->carry = '1';
		else
			pc->carry = NULL;
	}
}

void		ft_lld(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		i;

	pc->cr = cw->op_tab[13].ctc;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		if (arr[0] == T_DIR)
			ft_lddir(cw, pc);
		else
			ft_ldind(cw, pc);
	}
	else
		pc->index += 2;
	free(arr);
}
