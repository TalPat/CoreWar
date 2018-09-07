/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 12:42:27 by cking             #+#    #+#             */
/*   Updated: 2018/09/07 12:43:48 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "libft.h"
#include <stdlib.h>

int	ft_getind(t_cw *cw, int idx)
{
	int	i;
	int	val;
	int	mult;

	i = 0;
	val = 0;
	mult = 1;
	while (i < IND_SIZE)
	{
		val = val + (cw->mem[idx + IND_SIZE - i] * mult);
		mult *= 0xFF;
		i++;
	}
	return (val);
}