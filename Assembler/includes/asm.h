/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:50:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 10:54:34 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <stdlib.h>
#include "op.h"

#ifndef ASM_H
# define ASM_H

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
}				t_asm;

typedef struct	s_token
{
	char		*args;
	int			op_code;
	int			type[4];
	int			value[4];
	char		*lblname;
	char		*lblval[4];
}				t_token;
#endif