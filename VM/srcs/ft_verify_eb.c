/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_eb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 14:29:14 by cking             #+#    #+#             */
/*   Updated: 2018/09/07 14:48:52 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_verify_eb(t_cw *cw, t_pc *pc)
{
	int	*arr;
	int	idx;
	int	i;

	i = 0;
	idx = cw->mem[pc->index];
	arr = ft_getparam(cw->mem[pc->index + 1]);
	while (i < 4)
	{
		if (cw->op_tab[idx].arg[i])
		{
			if ((cw->op_tab[idx].arg[i] & arr[i]) != arr[i])
				return (0);
		}
		else
		{
			if (arr[i])
				return (0);
		}
		i++;
	}
	return (1);
}
