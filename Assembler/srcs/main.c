/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:49:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/26 09:25:43 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd = open("test.s", O_RDONLY);
	int size = ft_file_size("test.s");
	unsigned char *info;
	char **args;
	info = ft_store_info("test.s", size);
	args = ft_strsplit((char *)info, '\n');
	int i = 0;
	//while(1)
		//printf("%s\n",args[i++]);
}
