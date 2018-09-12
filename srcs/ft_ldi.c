/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:58:28 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 12:32:57 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_getmemval(t_cw *cw, int index, int size);

void		ft_ldi(t_cw *cw, t_pc *pc)
{
	int		newidx;
	int		s;
	int		ans;
	int		reg;
	int		*psize;

	pc->cr = cw->op_tab[10].ctc;
	newidx = 0;
	if (ft_verify_eb(cw, pc))
	{
		newidx += 2;
		psize = ft_getparam_size(cw->mem[pc->index + 1]);
		s = ft_getmemval(cw, pc->index + (ft_getmemval(cw, pc->index + newidx, psize[0])) % IDX_MOD, psize[1]) + 4;
		ft_putnbr(s);
		ft_putchar('\n');
		newidx += psize[0];
		ans = ft_getmemval(cw, pc->index + (s % IDX_MOD), psize[2]);
		ft_putnbr(ans);
		ft_putchar('\n');
		newidx += psize[1];
		reg = ft_atoi_base((char*)&cw->mem[pc->index + newidx], 10);
		ft_putnbr(reg);
		ft_putchar('\n');
		pc->registers[reg] = (unsigned char*)ft_itoa_base(ans, 16);
	}
}

int main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 10;
	cw->mem[1] = 228;
	cw->mem[2] = 0;
	cw->mem[3] = 4;
	cw->mem[4] = 0;
	cw->mem[5] = 4;
	cw->mem[6] = 2;
	cw->mem[7] = 4;
	cw->mem[8] = 84;
	cw->mem[9] = 2;
	cw->mem[10] = 3;
	cw->mem[11] = 4;
	pc->index = 0;

	ft_print_bits(cw, 0, 5);
	pc->registers[0] = (unsigned char*)"0";
	pc->registers[1] = (unsigned char*)"0";
	pc->registers[2] = (unsigned char*)"0";
	pc->registers[3] = (unsigned char*)"0";
	pc->registers[4] = (unsigned char*)"0";
	pc->registers[5] = (unsigned char*)"0";
	pc->registers[6] = (unsigned char*)"0";
	pc->registers[7] = (unsigned char*)"0";
	pc->registers[8] = (unsigned char*)"0";
	pc->registers[9] = (unsigned char*)"0";
	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
	ft_putchar('\n');
    pc->carry = 0;
	ft_ldi(cw, pc);
	//ft_putstr((char*)pc->registers[15]); //prints hex value
    //ft_putnbr(pc->index);
	//ft_putchar('\n');
	//ft_putnbr(pc->carry);
	//ft_ld(cw, pc);
}