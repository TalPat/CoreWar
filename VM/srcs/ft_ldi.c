/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:10:06 by cking             #+#    #+#             */
/*   Updated: 2018/12/11 13:38:02 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_getmemval(t_cw *cw, int index, int size);

void		ft_ldi(t_cw *cw, t_pc *pc)
{
    int     x; //value from first param in command
    int     y; //value from second param in command
    int     *params;
    int     *param_sizes;
    int     dest_reg;

    if (!pc->cr)
		pc->cr = cw->op_tab[10].ctc;
	pc->cyccomplete++;

    if (pc->cr == pc->cyccomplete && ft_verify_eb(cw, pc))
	{
		params = ft_getparam(cw->mem[pc->index + 1]);
        param_sizes = ft_getparam_size(cw->mem[pc->index + 1]);

/*
** Get first value dependant on type of value
*/

        if(params[0] == 1)
            x = ft_getregval(pc, ft_getmemval(cw,pc->index + 2, REG_SIZE));
        else if(params[0] == 2)
            x = ft_getdir(cw, pc->index + 2);
        else
            x  = ft_getind(cw, pc->index + 2);

/*
** Get second value dependant on type of value
*/
        if(params[1] == 1)
            y = ft_getregval(pc, ft_getmemval(cw,pc->index + 2 + param_sizes[0], REG_SIZE));
        else
            y = ft_getdir(cw, pc->index + 2 + param_sizes[0]);

/*
** Get reg number to be changed and set its value to indirect value of the sum of the two first parameters
*/
        dest_reg = ft_getmemval(cw,pc->index + param_sizes[0] + param_sizes[1], REG_SIZE);
        ft_set_reg_ind(cw,pc, (pc->index + x + y) % IDX_MOD, dest_reg);
        pc->index = (pc->index + param_sizes[0] + param_sizes[1] + REG_SIZE) % MEM_SIZE;
        pc->cr = 0;
        pc->cyccomplete = 0;
	}
    
}
