/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 16:10:31 by cking             #+#    #+#             */
/*   Updated: 2018/09/11 12:05:25 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

void		ft_lddir(t_cw *cw, t_pc *pc)
{
	int i;
	int regnum;

	i = 0;
	regnum = cw->mem[pc->index + 2 + DIR_SIZE];
	while (i < REG_SIZE)
	{
		pc->registers[regnum][i] = cw->mem[pc->index + 2 + i];
		i++;
	}
	pc->index = pc->index + 2 + DIR_SIZE;
}

void		ft_ldind(t_cw *cw, t_pc *pc)
{
	int regnum;
	int i;
	int offset;

	regnum = cw->mem[pc->index + 2 + IND_SIZE];
	i = 0;
	offset = ft_hextodec(ft_strsub((char *)cw->mem, pc->index + 2, IND_SIZE));
	while (i < REG_SIZE)
	{
		pc->registers[regnum][i] = cw->mem[pc->index + i + offset];
		i++;
	}
}

void		ft_ld(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		i;

	pc->cr = 5;
	if (ft_verify_eb(cw, pc))
	{
		arr = ft_getparam(cw->mem[pc->index + 1]);
		if (arr[0] == T_DIR)
			ft_lddir(cw, pc);
		else
			ft_ldind(cw, pc);
	}
	else
		pc->index += 2;
	free(arr);
}

int		main(void)
{
	t_cw			*cw;
	t_pc			*pc;
	int				i;

	cw = (t_cw *)malloc(sizeof(t_cw));
	pc = (t_pc *)malloc(sizeof(t_pc));
	ft_inittable(cw);
	cw->mem = (unsigned char*)malloc(sizeof(unsigned char) * MEM_SIZE);
	ft_bzero(cw->mem, MEM_SIZE);
	cw->mem[0] = 2;
	cw->mem[1] = 208;
	cw->mem[2] = 255;
	cw->mem[3] = 0;
	cw->mem[4] = 2;
	cw->mem[5] = 0;
	cw->mem[6] = 0;
	pc->index = 0;
	ft_print_bits(cw, 0, 7);
	pc->registers = (unsigned char **)malloc(sizeof(unsigned char *) * REG_NUMBER);
	i = 0;
	while (i < REG_NUMBER)
	{
		pc->registers[i] = (unsigned char *)malloc(sizeof(unsigned char) * REG_SIZE);
		ft_bzero(pc->registers[i], REG_SIZE);
		i++;
	}
	ft_ld(cw, pc);
	ft_print_reg(pc);
	ft_putnbr(ft_hextodec("ff00"));
}
