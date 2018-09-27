/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cull.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:41:24 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 18:07:13 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

void	ft_erasepc(t_cw *cw, t_list *tmp, t_list *prev)
{
	int	i;

	i = 0;
	if (prev)
		prev->next = tmp->next;
	else
		cw->pclist = tmp->next;
	while (i < REG_NUMBER)
	{
		//free(((t_pc*)(tmp->content))->registers[i]);
		i++;
	}
	free(((t_pc*)(tmp->content))->registers);
	free(tmp);
}

void	ft_cullpcs(t_cw *cw)
{
	t_list	*tmp;
	t_list	*prev;
	t_list	*next;

	prev = NULL;
	tmp = cw->pclist;
	while (tmp)
	{
		next = tmp->next;
		if (((t_pc*)(tmp->content))->live == 0)
		{
			/**///ft_print_reg((t_pc*)(tmp->content));
			ft_erasepc(cw, tmp, prev);
		}
		else
			prev = tmp;
		tmp = next;
	}
}

void	ft_cullplayers(t_cw *cw)
{
	t_list	*tplayer;
	t_list	*tpc;
	int		pcno;

	tplayer = cw->playerlist;
	while (tplayer)
	{
		pcno = 0;
		tpc = cw->pclist;
		while (tpc)
		{
			if (((t_player*)(tplayer->content))->idnbr ==
				((t_pc*)(tpc->content))->idnbr)
				pcno++;
			tpc = tpc->next;
		}
		if (!pcno)
			((t_player*)(tplayer->content))->live = 0;
		tplayer = tplayer->next;
	}
}

void	ft_checkplayers(t_cw *cw)
{
	int		i;
	t_list	*tmpplayer;
	t_list	*tmppc;

	tmpplayer = cw->playerlist;
	while (tmpplayer)
	{
		i = 0;
		tmppc = cw->pclist;
		while (tmppc)
		{
			if (((t_pc*)tmppc->content)->idnbr == ((t_player*)tmpplayer->content)->idnbr)
				if (((t_pc*)tmppc->content)->live == 1)
				{
					i = 1;
					((t_pc*)tmppc->content)->registers[15][3] = 3;
				}
			tmppc = tmppc->next;
		}
		((t_player*)tmpplayer->content)->live = 0;
		if (i)
			((t_player*)tmpplayer->content)->live = 1;
		tmpplayer = tmpplayer->next;
	}
}

void	ft_checkwinner(t_cw *cw)
{
	int		i;
	t_list	*tmp;

	tmp = cw->playerlist;
	i = 0;
	ft_checkplayers(cw);
	while (tmp)
	{
		if (((t_player*)(tmp->content))->live)
			i++;
		tmp = tmp->next;
	}
	if (i == 1)
		cw->gameover = 1;
	if (i == 0)
		cw->gameover = 2;
}

void	ft_cull(t_cw *cw)
{
	cw->cyclebase++;
	if (cw->cyclecounter < cw->cycle2die)
	{
		cw->cyclecounter++;
		return ;
	}
	ft_cullpcs(cw);
	ft_cullplayers(cw);
	ft_checkwinner(cw);
	cw->cycle2die -= CYCLE_DELTA;
	cw->cyclecounter = 0;
}
