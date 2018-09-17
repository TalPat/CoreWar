/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:53:27 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/14 13:28:20 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

int	main(int argc, char **argv)
{
	t_cw *cw;

	cw = (t_cw*)malloc(sizeof(t_cw));
	init_struct(cw);
	cw->error = ft_getargs(cw, argc, argv);
	if (cw->error)
	{
		ft_putendl("An error occured");
		return (0);
	}
	ft_read_player(cw, argv);
	ft_genpc(cw);
	ft_print_bits(cw, 0, MEM_SIZE);
	while (!cw->gameover)
	{
		ft_executepcs(cw);
		ft_cull(cw);
		ft_dump(cw);
	}
	ft_print_bits(cw, 0, MEM_SIZE);
	return (0);
}
