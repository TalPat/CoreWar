/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_crfirstpl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:47:48 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 09:48:46 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**initialise first player data
*/

void	ft_crfirstpl(t_cw *cw)
{
	t_player *player;

	cw->playerlist = (t_list *)malloc(sizeof(t_list));
	player = (t_player *)malloc(sizeof(t_player));
	player->live = 1;
	player->name = NULL;
	player->warcry = NULL;
	player->idnbr = -1;
	player->magic_num = NULL;
	cw->playerlist->content = player;
	cw->playerlist->next = NULL;
	cw->playerlist->content_size = sizeof(t_player);
}
