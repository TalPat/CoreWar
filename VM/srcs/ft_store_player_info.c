/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_player_info.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:49:07 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 09:50:48 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"
#include "fcntl.h"

unsigned char *ft_store_player_info(char *file, int size) // Store player file info into temp char **
{
	int fd;
	int i;
	int ret;
	unsigned char c;
	unsigned char *str;

	str = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_read_error_msg(1, file);
		return (NULL);
	}
	i = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			str[i++] = c;
		else if (ret == -1)
			ft_read_error_msg(2, file);
		if (ret < 1)
			break;
	}
	close(fd);
	return (str);
}