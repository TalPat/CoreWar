/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 15:04:50 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 16:01:00 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_addindex(t_token *tok, t_asm *asmb)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < 4)
	{
		if (tok->type[i] == T_REG)
			index += 1;
		if (tok->type[i] == T_DIR)
			index += DIR_SIZE;
		if (tok->type[i] == T_IND)
			index += IND_SIZE;
		if (asmb->op_tab[tok->op_code].dunno && tok->type[i] == T_IND)
			index += IND_SIZE / 2;
		i++;
	}
	return (index);
}

void	ft_getindex(t_asm *asmb)
{
	t_list	*tmp;
	int		index;
	t_token	*tok;

	tmp = asmb->tknlst;
	index = 0;
	while (tmp)
	{
		tok = tmp->content;
		tok->index = index;
		if (tok->op_code)
		{
			index++;
			if ((asmb->op_tab)[c].eb)
				index++;
			index += ft_addindex(tok, asmb);
		}
		tmp = tmp->next;
	}
}
