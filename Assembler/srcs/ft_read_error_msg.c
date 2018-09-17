/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_error_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:37:16 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 10:38:42 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void		ft_read_error_msg(int flag, char *file)
{
	if (flag == 1)
	{
		ft_putstr("Error opening file: ");
		ft_putstr(file);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Error reading from file: ");
		ft_putstr(file);
		ft_putchar('\n');
	}
}
