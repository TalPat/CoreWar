/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:50:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/25 15:05:16 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include "op.h"

#ifndef ASM_H
# define ASM_H

typedef struct		s_op
{
	char			*name;
	int				argc;
	int				arg[4];
	int				op_code;
	int				ctc;
	char			*desc;
	int				eb;
	int				dunno;
}					t_op;

typedef struct	s_label
{
	int			index;
	char		*name;
}				t_label;

typedef struct	s_asm
{
	t_list		*lbllst;
	t_list		*tknlst;
	int			error[16];
	int			errorcnt;
	int			fd;
	char		*namecor;
	char		*names;
	t_op		op_tab[17];
}				t_asm;

typedef struct	s_token
{
	char		*args;
	int			op_code;
	int			type[4];
	int			value[4];
	char		*lblname;
	char		*lblval[4];
	int			index;
}				t_token;

void				ft_createfile(t_asm *asmb);
void				ft_append(int tokenno, t_asm *asmb);
void				ft_getindex(t_asm *asmb);
int					ft_buildeb(t_token *tok);
char				*ft_trim(char *str);
void				ft_inittable(t_asm *asmb);
void				ft_initasm(t_asm *asmb);

#endif
