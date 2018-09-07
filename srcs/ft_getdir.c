/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:58:26 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/07 12:09:31 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "libft.h"
#include <stdlib.h>

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
		val = val + (cw->mem[idx + DIR_SIZE - i] * mult);
		mult *= 0xFF;
		i++;
	}
	return (val);
}
