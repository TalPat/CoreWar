/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:34:23 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 10:36:56 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_count_players(char **players)
{
	int i;
	int count;

	i = 1;
	count = 0;
	while (players[i])
	{
		if (!ft_strcmp(players[i] + ft_strlen(players[i]) - 4, ".cor"))
			count++;
		i++;
	}
	return (count);
}
