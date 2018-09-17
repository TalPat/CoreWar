/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:43:45 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 09:44:05 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void ft_init_player_list(t_cw *cw, int npl) //	Create player list and initialise
{
	int i;
	t_list *tmplist;
	t_player *tmpplayer;

	if (!cw->playerlist)
		ft_crfirstpl(cw);
	i = 1;
	while (i < npl)
	{
		tmpplayer = (t_player *)malloc(sizeof(t_player));
		tmpplayer->live = 1;
		tmpplayer->name = NULL;
		tmpplayer->warcry = NULL;
		tmpplayer->idnbr = -i - 1;
		tmpplayer->magic_num = NULL;
		tmplist = (t_list *)malloc(sizeof(t_list));
		tmplist->content = tmpplayer;
		tmplist->content_size = sizeof(t_player);
		ft_lstadd(&(cw->playerlist), tmplist);
		i++;
	}
}
