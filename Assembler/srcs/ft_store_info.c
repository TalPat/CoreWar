/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 09:08:06 by cking             #+#    #+#             */
/*   Updated: 2018/09/26 10:02:27 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "asm.h"

unsigned char	*ft_store_info(char *file, int size)
{
	int				fd;
	int				i;
	int				ret;
	unsigned char	c;
	unsigned char	*str;

	str = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			str[i++] = c;
		if (ret < 1)
			break ;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}
