/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:53:27 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/27 13:05:39 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_cw *cw;
	t_pc *pc;
	WINDOW *win;
	WINDOW *win2;

	
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
	initscr();
	win = newwin(66, 195, 2, 5);//height, width, start y, start x
	win2 = newwin(20, 50, 2, 205);
	ft_viz(cw, ((t_pc*)cw->pclist->content), win, win2);
	//ft_print_bits(cw, 0, MEM_SIZE);
	while (!cw->gameover)
	{
		ft_executepcs(cw);
		ft_cull(cw);
		ft_dump(cw);
		ft_viz2(cw, ((t_pc *)cw->pclist->content), win, win2);
		//cw->pclist = cw->pclist->next;
		//ft_viz(cw, pc);
	}
	//ft_viz2(cw, pc, win, win2);
	endwin();
	//ft_print_bits(cw, 0, MEM_SIZE);
	return (0);
}
