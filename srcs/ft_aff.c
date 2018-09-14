/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 13:43:42 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 11:07:44 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	ft_aff(t_cw *cw, t_pc *pc)
{
	int				newidx;
	int				reg;
	int				ans;

	if (!pc->cr)
		pc->cr = cw->op_tab[16].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 0;
		if (ft_verify_eb(cw, pc))
		{
			newidx += 2;
			reg = cw->mem[pc->index + newidx] - 1;
			ft_putchar('\n');
			ans = ft_atoi_base((char*)pc->registers[reg], 10) % 256;
			ft_putchar(ans);
		}
		pc->index += newidx + 1;
		pc->cyccomplete = 0;
	}
}
