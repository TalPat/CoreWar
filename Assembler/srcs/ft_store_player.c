/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 10:02:16 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 10:08:23 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void	ft_store_player(t_cw *cw, unsigned char *info, int pos, int incr)
{
	int		i;
	t_list	*tmp;

	i = -1;
	tmp = cw->playerlist;
	while (++i < incr)
		tmp = tmp->next;
	((t_player *)(tmp->content))->magic_num = ft_strndup((const char *)info, 4);
	((t_player *)(tmp->content))->name =
	ft_strndup((const char *)(info + 4), 138);
	((t_player *)(tmp->content))->progsize =
	((int)(*(info + 138)) * 256 + (int)(*(info + 139)));
	((t_player *)(tmp->content))->warcry =
	ft_strndup((const char *)(info + 140), 2192);
	((t_player *)(tmp->content))->startidx = pos;
	i = pos;
	while (i < (pos + ((t_player *)(tmp->content))->progsize))
	{
		cw->mem[i] = info[i - pos + 2192];
		i++;
	}
}
