/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:06:19 by cking             #+#    #+#             */
/*   Updated: 2018/09/26 09:17:41 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <unistd.h>
#include <fcntl.h>

int			ft_file_size(char *file)
{
	int				i;
	int				fd;
	int				ret;
	unsigned char	c;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			i++;		
		if (ret < 1)
			break ;
	}
	close(fd);
	return (i);
}
