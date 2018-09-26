/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:49:13 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/26 10:19:53 by cking            ###   ########.fr       */
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
	printf("main: %d\n", size);
	info = ft_store_info("test.s", size);
	args = ft_strsplit((char *)info, '\n');
	int i = 0;
	while(args[i])
		printf("Token[%d]: %s\n", i, args[i++]);
}
