/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:38:54 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/14 10:40:21 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_read_player(t_cw *cw, char **players)
{
	int				mem;
	int				npl;
	int				i;
	unsigned char	*str;

	npl = ft_count_players(players);
	ft_init_player_list(cw, npl);
	mem = (MEM_SIZE) / (npl);
	i = 1;
	while (i <= npl)
	{
		str = ft_store_player_info(players[i], ft_file_size(players[i]));
		ft_store_player(cw, str, mem * (i - 1), npl - i);
		i++;
	}
	return (0);
}

// int main(int argc, char **argv)
// {
// 	t_cw *cw;

// 	argc = 0;
// 	cw = (t_cw *)malloc(sizeof(t_cw));
// 	ft_inittable(cw);
// 	init_struct(cw);
// 	ft_print_bits(cw, 0, MEM_SIZE);
// 	ft_read_player(cw, argv);
// 	ft_print_bits(cw, 0, MEM_SIZE);
// 	ft_print_player_data(cw, ft_count_players(argv));
// 	return (0);
// }