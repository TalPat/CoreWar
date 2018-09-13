/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getargs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 12:51:05 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/13 17:11:19 by tpatter          ###   ########.fr       */
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
		if (!ft_strcmp(argv[i], "-dump"))
		{
			i++;
			if (ft_isnum(argv[i]))
			{
				cw->dump = 1;
				cw->dumpno = ft_atoi(argv[i]);
				i++;
			}
			else
				return (2);
		}
		else if (!ft_strcmp(argv[i], "-n"))
		{
			i++;
			if (ft_isnum(argv[i]) && !ft_strcmp(argv[i + 1] +
				ft_strlen(argv[i + 1]) - 4, ".cor"))
				i += 2;
			else
				return (2);
		}
		else if (!ft_strcmp(argv[i], "-v"))
		{
			cw->visualiser = 1;
			i++;
		}
		else if (!ft_strcmp(argv[i] + ft_strlen(argv[i]) - 4, ".cor"))
			i++;
		else
			return (3);
	}
	return (0);
}
