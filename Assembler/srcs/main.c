/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:33:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/11 17:10:31 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include <stdio.h>

int		main (int argc, char **argv)
{
	t_cw *cw;

	argc = 0;
	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	init_struct(cw);
	ft_print_bits(cw, 0, MEM_SIZE);
	ft_read_player(cw, argv); // Segfault
	ft_print_bits(cw, 0, MEM_SIZE);
	return (0);
}