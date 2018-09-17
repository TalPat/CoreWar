/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfork.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:27:06 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 13:36:23 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

void	ft_lforkbuildpc(t_cw *cw, t_pc *pc, t_pc *newpc)
{
	int	i;

	newpc->index = (pc->index + (ft_getind(cw, pc->index + 1))) % MEM_SIZE;
	newpc->idnbr = pc->idnbr;
	newpc->cr = pc->cr;
	newpc->carry = pc->carry;
	newpc->registers = (unsigned char**)malloc(sizeof(char*) * REG_NUMBER);
	i = 0;
	while (i < REG_NUMBER)
	{
		newpc->registers[i] = (unsigned char*)malloc(sizeof(char)
			* REG_SIZE);
		ft_memcpy(newpc->registers[i], pc->registers[i], REG_SIZE);
		i++;
	}
}

void	ft_lfork(t_cw *cw, t_pc *pc)
{
	int		newidx;
	t_list	*newpclist;
	t_pc	*newpc;

	if (!pc->cr)
		pc->cr = cw->op_tab[15].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newpc = (t_pc*)malloc(sizeof(pc));
		newpclist = (t_list*)malloc(sizeof(t_list));
		newpclist->content = newpc;
		newpclist->content_size = sizeof(t_pc);
		ft_lstadd(&(cw->pclist), newpclist);
		if (newpc->index == 0)
			pc->carry = 1;
		newidx = IND_SIZE;
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}
