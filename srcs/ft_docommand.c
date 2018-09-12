/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_docommand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 15:10:08 by talon             #+#    #+#             */
/*   Updated: 2018/09/12 15:42:31 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"
#include "op.h"

/*
**Find and execute the relevent function which the given pc points to. Should
**the pc not point to an operation, the pc is incremented to point to the next
**byte in memory. If the pc does point to the function, pc must be incremented
**by the function that it executes.
*/

void	ft_comcont(t_cw *cw, unsigned char com, t_pc *pc)
{
	if (com == 0x0a)
		ft_ldi(cw, pc);
	else if (com == 0x0b)
		ft_sti(cw, pc);
	else if (com == 0x0c)
		ft_fork(cw, pc);
	else if (com == 0x0d)
		ft_lld(cw, pc);
	else if (com == 0x0e)
		ft_lldi(cw, pc);
	else if (com == 0x0f)
		ft_lfork(cw, pc);
	else if (com == 0x10)
		ft_aff(cw, pc);
	else
		pc->index++;
}

void	ft_docommand(t_cw *cw, t_pc *pc)
{
	unsigned char	com;

	com = cw->mem[pc->index];
	if (com == 0x01)
		ft_live(cw, pc);
	else if (com == 0x02)
		ft_ld(cw, pc);
	else if (com == 0x03)
		ft_st(cw, pc);
	else if (com == 0x04)
		ft_add(cw, pc);
	else if (com == 0x05)
		ft_sub(cw, pc);
	else if (com == 0x06)
		ft_and(cw, pc);
	else if (com == 0x07)
		ft_or(cw, pc);
	else if (com == 0x08)
		ft_xor(cw, pc);
	else if (com == 0x09)
		ft_zjmp(cw, pc);
	else if (com > 0x09)
		ft_comcont(cw, com, pc);
}
