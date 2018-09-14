/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 16:47:55 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 14:07:12 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

void	ft_dump(t_cw *cw)
{
	if (cw->dump && cw->cyclebase == cw->dumpno)
		ft_print_bits(cw, 0, MEM_SIZE);
}
