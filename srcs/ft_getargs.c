/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:51:05 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/13 13:16:34 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include <stdlib.h>

int	ft_getargs(t_cw *cw, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
		return (1);
	while (i < argc)
	{
		if (!ft_strcmp(argv[i],"-dump"))
		{
			if (ft_isnum(argv[i + 1]))
			{
				cw->dump = 1;
				cw->dumpno = ft_atoi(argv[i + 1]);
			}
			else
				return (2);
		}
	}
}