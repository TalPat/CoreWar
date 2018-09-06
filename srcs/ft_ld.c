/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:10:31 by cking             #+#    #+#             */
/*   Updated: 2018/09/06 16:07:14 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void		ft_ld(t_cw *cw, t_pc *pc)
{
	int		*arr;

	pc->cr = 5;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
	}
	else
		pc->index++;
}
