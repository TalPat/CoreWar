/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 16:23:36 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/26 09:03:01 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	main(int ac, char **av)
{
	t_asm	*asmb;

	asmb = (t_asm*)malloc(sizeof(t_asm));
	ft_initasm(asmb);
	return (0);
}
