/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:59:38 by cking             #+#    #+#             */
/*   Updated: 2018/09/04 16:59:38 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ft_live(t_cw *cw, t_pc *pc)
{
	char		*str;
	int			plr_nbr;
	t_player	*cursor;

	str = ft_strsub(cw->mem, pc->index, DIR_SIZE);
	plr_nbr = ft_atoi(str);
	cursor = cw->players;
	while (cursor)
	{
		if (cursor->nbr == plr_nbr)
			cursor->alive == 1;
		cursor = cursor->next;
	}
	pc = pc + DIR_SIZE;
}
