/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_createfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 10:47:46 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/24 12:51:14 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include <fcntl.h>

void	ft_createfile(t_asm *asmb)
{
	asmb->fd = open(asmb->namecor, O_RDWR | O_APPEND | O_TRUNC | O_CREAT,
		S_IRUSR, S_IWUSR);
	if (asmb->fd < 0)
	{
		asmb->error[asmb->errorcnt] = 1;
		asmb->errorcnt++;
	}
}
