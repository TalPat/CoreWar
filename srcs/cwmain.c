/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:53:27 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 17:27:58 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

int	main(int argc, char **argv)
{
	t_cw *cw;

	cw = (t_cw*)malloc(sizeof(t_cw));
	init_struct(cw);
	return (0);
}