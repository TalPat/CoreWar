/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:51:30 by cking             #+#    #+#             */
/*   Updated: 2018/09/26 12:31:39 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void		ft_live(t_cw *cw, t_pc *pc)
{
	char					*str;
	unsigned int			plr_nbr;
	t_list					*cursor;

	if (!pc->cr)
		pc->cr = cw->op_tab[1].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		str = ft_strsub((const char *)cw->mem, pc->index + 1, DIR_SIZE);
		plr_nbr = ft_atoi(str);
		cursor = cw->playerlist;
		while (cursor)
		{
			if (((t_player *)(cursor->content))->idnbr == plr_nbr)
				((t_player *)(cursor->content))->live = 1;
			cursor = cursor->next;
		}
		pc->index = pc->index + DIR_SIZE + 1;
		cw->nbr_live_calls++;
		free(str);
		pc->cyccomplete = 0;
		pc->cr = 0;
	}
}
