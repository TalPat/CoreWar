/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:03:01 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 11:15:05 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_build(t_token *tok, t_asm *asmb)
{

}

void	ft_append(int tokenno, t_asm *asmb)
{
	t_list	*tmp;
	int		i;
	t_token	*tok;

	tmp = asmb->tknlst;
	i = 0;
	while (i < tokenno)
	{
		i++;
		tmp = tmp->next;
	}
	tok = tmp->content;
	if (tok->op_code)
		ft_build(tok, asmb);
	if (tmp->next)
		ft_appennd(++tokenno, asmb);
}
