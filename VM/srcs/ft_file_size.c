/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:33:41 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 10:34:00 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"
#include "fcntl.h"

int			ft_file_size(char *file) // Count bytes to malloc for
{
	int				i;
	int				fd;
	int				ret;
	unsigned char	c;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_read_error_msg(1, file);
		return (0);
	}
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			i++;
		else if (ret == -1)
			ft_read_error_msg(2, file);
		if (ret < 1)
			break ;
	}
	close(fd);
	return (i);
}
