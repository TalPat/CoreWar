/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:47:46 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 11:01:44 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

void	ft_createfile(t_asm *asmb)
{
	asmb->fd = open(asmb->namecor, O_RDWR | O_APPEND);
	if (asmb->fd < 0)
	{
		asmb->error[asmb->errorcnt] = 1;
		asmb->errorcnt++;
	}
}
