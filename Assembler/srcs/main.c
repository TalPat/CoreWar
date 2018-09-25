/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:49:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 16:15:08 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../includes/asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

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

char *ft_store_info(char *file, int size) // Store player file info into temp char **
{
	int fd;
	int i;
	int ret;
	unsigned char c;
	unsigned char *str;

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
			break;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

int		main(int ac, char **av)
{
	int fd = open("test.s", O_RDONLY);
	int size = ft_file_size("test.s");
	char *info;
	char **args;
	info = ft_store_info("test.s", size);
	args = ft_strsplit(info, '\n');

}
