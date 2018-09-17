/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_player_data.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 09:29:13 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 09:39:00 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_print_player_data(t_cw *cw, int npl)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = cw->playerlist;
	while (i < npl)
	{
		write(1, "\nName: ", 7);
		ft_putstr(((t_player *)(tmp->content))->name);
		write(1, "\nWarcry: ", 9);
		ft_putstr(((t_player *)(tmp->content))->warcry);
		write(1, "\nLive: ", 7);
		ft_putnbr(((t_player *)(tmp->content))->live);
		write(1, "\nID: ", 5);
		ft_putnbr(((t_player *)(tmp->content))->idnbr);
		write(1, "\nMagic: ", 8);
		ft_putstr(((t_player *)(tmp->content))->magic_num);
		write(1, "\nProgsize: ", 11);
		ft_putnbr(((t_player *)(tmp->content))->progsize);
		write(1, "\n", 1);
		tmp = tmp->next;
		i++;
	}
}
