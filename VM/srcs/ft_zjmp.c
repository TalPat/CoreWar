/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:59:54 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 10:54:10 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_zjmp(t_cw *cw, t_pc *pc)
{
	int				newidx;

	if (!pc->cr)
		pc->cr = cw->op_tab[9].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 0;
		if (pc->carry == 1)
			newidx = ft_getdir(cw, pc->index + 1);
		else
			newidx = DIR_SIZE + 1;
		pc->index += newidx;
		pc->cyccomplete = 0;
	}
}
