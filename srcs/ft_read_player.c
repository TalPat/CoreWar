/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:38:54 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/10 16:56:03 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

int	ft_read_player(t_cw *cw, const int fd)
{
	int				i;
	int				ret;
	unsigned char	c;

	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) *
		(ft_count_bits(fd)));
	i = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
		{
			cw->mem[i] = c;
			i++;
		}
		else if (ret == -1)
			return (-1);
		else
			return (i);
	}
	return (i);
}

int	ft_count_bits(const int fd)
{
	int				i;
	int				ret;
	unsigned char	c;

	i = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			i++;
		else if (ret == -1)
			return (-1);
		else
			return (i);
	}
	return (0);
}