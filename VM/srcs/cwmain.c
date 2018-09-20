/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:53:27 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/20 11:39:49 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

int	main(int argc, char **argv)
{
	t_cw *cw;
	t_pc *pc;

	cw = (t_cw*)malloc(sizeof(t_cw));
	init_struct(cw);
	cw->error = ft_getargs(cw, argc, argv);
	if (cw->error)
	{
		ft_putendl("An error occured");
		return (0);
	}
	ft_read_player(cw, argv);
	//ft_viz(cw, pc);
	ft_genpc(cw);
	//ft_print_bits(cw, 0, MEM_SIZE);
	while (!cw->gameover)
	{
		ft_viz(cw, pc);
		ft_executepcs(cw);
		ft_cull(cw);
		ft_dump(cw);
		//ft_viz(cw, pc);
	}
	ft_viz(cw, pc);
	endwin();
	//ft_print_bits(cw, 0, MEM_SIZE);
	return (0);
}
