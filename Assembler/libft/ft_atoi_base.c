/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 13:44:01 by jde-agr           #+#    #+#             */
/*   Updated: 2018/09/05 13:44:32 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str, int str_base)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	if (str == '\0')
		return (0);
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while ((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')
			|| (str[i] >= 'A' && str[i] <= 'F'))
	{
		if (str[i] >= 'a' && str[i] <= 'f')
			num = (num * str_base) + (10 + ((str[i++] - 'a') % 'a'));
		else if (str[i] >= 'A' && str[i] <= 'F')
			num = (num * str_base) + (10 + ((str[i++] - 'A') % 'A'));
		else
			num = (num * str_base) + (str[i++] - '0');
	}
	return (num * sign);
}
