/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:30:29 by cking             #+#    #+#             */
/*   Updated: 2018/09/28 13:34:01 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

char	**ft_get_args(char *file_name)
{
	int				fd;
	int				size;
	unsigned char	*info;
	char			**out;
	int				i;

	i = 0;
	fd = open(file_name, O_RDONLY);
	size = ft_file_size(file_name);
	info = ft_store_info("test.s", size);
	out = ft_strsplit((char *)info, '\n');
	while (out[i])
		out[i] = ft_trim(out[i]);
	return (out);
}
