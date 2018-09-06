/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:21:14 by jde-agr           #+#    #+#             */
/*   Updated: 2018/09/06 16:27:21 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	init_struct(t_cw *cw)
{
	cw->nbrplayers = 0;
	cw->mem = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	cw->cyclecounter = 0;
	ft_inittable(cw);
	cw->cycle2die = CYCLE_TO_DIE;
	cw->cycledelta = CYCLE_DELTA;
}
