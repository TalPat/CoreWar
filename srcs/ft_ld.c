/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:10:31 by cking             #+#    #+#             */
/*   Updated: 2018/09/06 17:04:08 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void		ft_ld(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		argsize;
	char	*temp;

	pc->cr = 5;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		if (arr[0] == T_DIR)
			argsize = DIR_SIZE;
		else
			argsize = IND_SIZE;

		temp = ft_strsub(cw->mem, pc->index + 2, argsize);
		pc->index = pc->index + 2 + argsize;
		pc->registers[cw->mem[pc->index]] = temp;
		pc->index++;
		free(temp);
	}
	else
		pc->index += 2;
}
