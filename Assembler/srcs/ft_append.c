/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 11:03:01 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 14:27:25 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_buildval(t_token *tok, t_asm *asmb, int i)
{
	int				bytes;
	int				j;
	unsigned char	c;

	if (tok->type[i] == T_REG)
		bytes = 1;
	if (tok->type[i] == T_DIR)
		bytes = DIR_SIZE;
	if (tok->type[i] == T_IND)
		bytes = IND_SIZE;
	if (asmb->op_tab[tok->op_code].dunno && tok->type[i] == T_IND)
		bytes = IND_SIZE / 2;
	j = 0;
	while (i < bytes)
	{
		ft_memcpy(&c, (unsigned char)(tok->value + i) + sizeof(int) - j, 1);
		write(asmb->fd, &c, 1);
		i++;
	}
}

void	ft_buildlbl(t_token *tok, t_asm *asmb, int i)
{
	t_list	*tmp;
	int		val;

	tmp = asmb->tknlst;
	while (tmp)
	{
		if (((t_token*)(tmp->content))->args == tok->lblval[i])
		{
			val = ((t_token*)(tmp->content))->index - tok->index;
			tok->value[i] = val;
			break ;
		}
		tmp = tmp->next;
	}
	ft_buildval(tok, asmb, i);
}

void	ft_build(t_token *tok, t_asm *asmb)
{
	char	c;
	int		i;

	i = 0;
	c = (unsigned char)(tok->op_code);
	write(asmb->fd, &c, 1);
	if ((asmb->op_tab)[c].eb)
	{
		c = (unsigned char)ft_buildeb(tok);
		write(asmb->fd, &c, 1);
	}
	while (i < 4)
	{
		if (tok->lblval[i])
			ft_buildlbl(tok, asmb, i);
		else if (tok->type[i])
			ft_buildval(tok, asmb, i);
		i++;
	}
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
		ft_append(++tokenno, asmb);
}
