/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:38:54 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/10 18:18:53 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include "fcntl.h"

void	ft_store_player(t_cw *cw, char *file, int pos)
{
	int				i;
	int				fd;
	int				ret;
	unsigned char	c;

	fd = open(file, O_RDONLY);
	i = pos;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1 && i < (pos + MEM_SIZE * 8))
		{
			cw->mem[i] = c;
			i++;
		}
		else
			break ;
	}
	close(fd);
}

int	ft_count_players(char **players)
{
	int i;

	i = 0;
	while (players[i][0] != '\0')
		i++;
	return (i);
}

int	ft_read_player(t_cw *cw, char **players)
{
	int mem;
	int npl;
	int i;

	npl = ft_count_players(players);
	mem = (8 * MEM_SIZE) / (npl);
	i = 0;
	while (i < npl)
	{
		ft_store_player(cw, players[i], mem * i);
		i++;
	}

}