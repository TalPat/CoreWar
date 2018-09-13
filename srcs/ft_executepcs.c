/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_executepcs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 14:24:40 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/13 17:25:14 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

void	ft_executepcs(t_cw *cw)
{
	t_list	*tplayer;
	t_list	*tpc;

	tplayer = cw->playerlist;
	while (tplayer)
	{
		/**/ft_putendl("Righto");
		tpc = cw->pclist;
		while (tpc)
		{
			if (((t_player*)(tplayer->content))->idnbr ==
				((t_pc*)(tpc->content))->idnbr)
			{
				/**/ft_putendl("Carry on then");
				ft_docommand(cw, tpc->content);
			}
			tpc = tpc->next;
		}
		tplayer = tplayer->next;
	}
}
