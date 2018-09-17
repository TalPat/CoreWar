/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_reg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 17:20:47 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 17:23:33 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_free_reg(unsigned char **reg)
{
	int i;

	i = 0;
	while (i < REG_NUMBER)
		free(reg[i++]);
	free(reg);
}
