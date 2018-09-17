/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 13:50:04 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/17 14:02:52 by tpatter          ###   ########.fr       */
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

#endif