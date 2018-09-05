/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:59:38 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 15:20:57 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

ft_live(t_cw *cw, t_pc *pc)
{
	char		*str;
	int			plr_nbr;
	t_list		*cursor;

	str = ft_strsub(cw->mem, pc->index+1, DIR_SIZE);
	plr_nbr = ft_atoi(str);
	cursor = cw->playerlist;
	while (cursor)
	{
		if (((t_player *)(cursor->content))->idnbr == plr_nbr)
			((t_player *)(cursor->content))->live == 1;
		cursor = cursor->next;
	}
	pc = pc + DIR_SIZE;
	pc->cr = 10;
}
