/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:58:26 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 10:52:07 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

/*
**credit tpatter
*/

int	ft_getdir(t_cw *cw, int idx)
{
	int	i;
	int	val;
	int	mult;

	i = 0;
	val = 0;
	mult = 1;
	while (i < DIR_SIZE)
	{
		val += (cw->mem[idx + DIR_SIZE - i - 1] * mult);
		mult *= 256;
		i++;
	}
	return (val);
}
