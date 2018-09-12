/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_reg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 12:18:15 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 12:52:25 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**Sets registry given of PC given value in memory at index given
*/

void		ft_set_reg_reg(t_pc *pc, int reg_src, int reg_dst)
{
	int i;

	i = 0;
	while (i < REG_SIZE)
	{
		pc->registers[reg_dst][i] = pc->registers[reg_src][i];
		i++;
	}
}

void		ft_set_reg_ind(t_cw *cw, t_pc *pc, int index, int reg_num)
{

}

void		ft_set_reg_redir(t_cw *cw, t_pc *pc, int index, int reg_num)
{

}
