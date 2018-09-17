/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:50:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/17 15:25:26 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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
}				t_asm;

typedef struct	s_token
{
	int			opcode;
	char		*args;
}				t_token;
#endif