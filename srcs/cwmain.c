/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cwmain.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 16:53:27 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/12 17:56:24 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"

int	main(int argc, char **argv)
{
	t_cw *cw;

	cw = (t_cw*)malloc(sizeof(t_cw));
	init_struct(cw);

	while (!cw->gameover)
	{
		if (cw->error)
		{
			//ft_memclean(cw);
			ft_putendl("An error occured");
			return (0);
		}
	}
	//ft_memclean(cw);
	return (0);
}
