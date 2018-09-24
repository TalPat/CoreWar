/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buildeb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 12:34:25 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 12:41:10 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	ft_buildeb(t_token *tok)
{
	int	eb;
	int	i;
	int	mult;

	eb = 0;
	i = 0;
	mult = 1;
	while (i < 4)
	{
		if (tok->type[i] == T_REG)
			eb += 1 * mult;
		if (tok->type[i] == T_DIR)
			eb += 2 * mult;
		if (tok->type[i] == T_IND)
			eb += 4 * mult;
		mult *= 4;
		i++;
	}
	return (eb);
}