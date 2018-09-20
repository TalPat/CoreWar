/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:21:14 by jde-agr           #+#    #+#             */
/*   Updated: 2018/09/20 14:04:24 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

void	init_struct(t_cw *cw)
{
	cw->playerlist = NULL;
	cw->nbrplayers = 0;
	cw->pclist = NULL;
	cw->mem = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw->memp = (int*)malloc(sizeof(int) * MEM_SIZE);
	cw->cyclecounter = 0;
	cw->cyclebase = 0;
	ft_inittable(cw);
	cw->cycle2die = CYCLE_TO_DIE;
	cw->cycledelta = CYCLE_DELTA;
	cw->nbr_live_calls = NBR_LIVE;
	cw->options = 0;
	cw->gameover = 0;
	cw->error = 0;
	cw->dump = 0;
	cw->dumpno = 0;
}
