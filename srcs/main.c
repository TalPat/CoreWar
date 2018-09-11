/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 12:33:42 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/11 13:51:44 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

int main (int argc, char **argv)
{
	argc = 0;
	argv = NULL;
	t_cw *cw;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	init_struct();
	return (0);
}