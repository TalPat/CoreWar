/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:13:33 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/10 16:31:10 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
** No comment yet.
*/

void	ft_and(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		val[3];

	pc->cr = cw->op_tab[6].ctc;
	newidx = 0;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		newidx += 1;
		if (arr[0] = T_REG)
		{
			newidx += 1;
			val[0] = ft_getregval(pc, cw->mem[pc->index + newidx]);
		}
		pc->index += newidx + 1;
	}
	pc->index++;
}
