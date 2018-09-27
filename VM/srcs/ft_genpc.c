/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_genpc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 17:26:47 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 13:11:08 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

void	ft_genpc(t_cw *cw)
{
	t_list	*tmp;
	t_list	*pclist;
	t_pc	*pc;
	int		i;
	int		zero;

	zero = 0;
	tmp = cw->playerlist;
	while (tmp)
	{
		i = 0;
		if (!cw->pclist)
		{
			cw->pclist = (t_list*)malloc(sizeof(t_list));
			pc = (t_pc*)malloc(sizeof(t_pc));
			pc->index = ((t_player*)(tmp->content))->startidx;
			pc->idnbr = ((t_player*)(tmp->content))->idnbr;
			pc->cr = 0;
			pc->cyccomplete = 0;
			pc->registers = (unsigned char**)malloc(sizeof(char*) * REG_NUMBER);
			while (i < REG_NUMBER)
			{
				pc->registers[i] = (unsigned char*)&zero;
				i++;
			}
			ft_memcpy(pc->registers[1], &(((t_player*)(tmp->content))->idnbr),
					REG_SIZE);
			pc->carry = 0;
			pc->live = 0;
			cw->pclist->content = pc;
			cw->pclist->next = NULL;
		}
		else
		{
			pclist = (t_list*)malloc(sizeof(t_list));
			pc = (t_pc*)malloc(sizeof(t_pc));
			pc->index = ((t_player*)(tmp->content))->startidx;
			pc->idnbr = ((t_player*)(tmp->content))->idnbr;
			pc->cr = 0;
			pc->cyccomplete = 0;
			pc->registers = (unsigned char**)malloc(sizeof(char*) * REG_NUMBER);
			while (i < REG_NUMBER)
			{
				pc->registers[i] = (unsigned char*)&zero;
				i++;
			}
			ft_memcpy(pc->registers[1], &(((t_player*)(tmp->content))->idnbr),
					REG_SIZE);
			pc->carry = 0;
			pc->live = 0;
			pclist->content = pc;
			ft_lstadd(&(cw->pclist), pclist);
		}
		tmp = tmp->next;
	}
}
