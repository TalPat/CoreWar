/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 12:21:14 by jde-agr           #+#    #+#             */
/*   Updated: 2018/09/04 15:40:38 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	init_struct(t_cornfield *cf)
{
	cf->field = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	cf->pcs = (t_corn*)malloc(sizeof(t_corn) * 1);
	cf->cycles = 0;
}
