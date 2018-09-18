/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 09:58:28 by cking             #+#    #+#             */
/*   Updated: 2018/09/18 11:24:17 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cw.h"

int		ft_getmemval(t_cw *cw, int index, int size);

int	ft_getdir(t_cw *cw, int idx);

void		ft_ldi(t_cw *cw, t_pc *pc)
{
	int		newidx;
	int		s;
	int		ans;
	int		reg;
	int		*psize;
	int		*parm;

	pc->cr = cw->op_tab[10].ctc;
	newidx = 0;
	if (ft_verify_eb(cw, pc))
	{
		newidx += 2;
		psize = ft_getparam_size(cw->mem[pc->index + 1]);
		parm = ft_getparam(cw->mem[pc->index + 1]);
		if (parm[0] == 1 && parm[1] == 2) //wip reg, dir, reg
			s = ft_getmemval(cw, pc->index + (ft_getmemval(cw, pc->index + newidx , 1) % IDX_MOD), psize[0]) + ft_getmemval(cw, pc->index + newidx + 1 , 4);//ft_getdir(cw, pc->index + newidx + 4);
		else if (parm[0] == 1 && parm[1] == 1) //wip reg, reg, reg
			s = ft_atoi_base((char*)pc->registers[cw->mem[pc->index + newidx] - 1], 16) + ft_atoi_base((char*)pc->registers[cw->mem[pc->index + newidx + 1] - 1], 16);
		else if (parm[0] == 2 && parm[1] == 2) //dir, dir, reg
			s = ft_getmemval(cw, pc->index + (ft_getmemval(cw, pc->index + newidx , psize[0]) % IDX_MOD), psize[0]) + ft_getdir(cw, pc->index + newidx + 4);
		else if (parm[0] == 2 && parm[1 == 1]) // wip dir, reg, reg
			s = ft_getmemval(cw, pc->index + newidx, 2) + ft_atoi_base((char*)pc->registers[cw->mem[pc->index + newidx + 2] - 1], 16);
		else if (parm[0] == 4 && parm[1] == 2) //ind, dir, reg
			s = ft_getmemval(cw, pc->index + (ft_getmemval(cw, pc->index + newidx , psize[0]) % IDX_MOD), psize[0]) + ft_getdir(cw, pc->index + newidx + 2);
		else if (parm[0] == 4 && parm[1] == 1)
			s = ft_getmemval(cw, pc->index + newidx, 2) + ft_atoi_base((char*)pc->registers[cw->mem[pc->index + newidx + 2] - 1], 16);
		ft_putstr("Dir val : ");
		ft_putnbr(ft_getmemval(cw, pc->index + newidx, 2));//ft_getdir(cw, pc->index + newidx + 4));//ft_getmemval(cw, pc->index + newidx , psize[0]) );//ft_getdir(cw, pc->index + newidx + 4));
		ft_putchar('\n');
		//ft_putstr("Reg val : ");
		//ft_putnbr(ft_atoi_base((char*)pc->registers[cw->mem[pc->index + newidx] - 1], 16));
		//ft_putchar('\n');
		ft_putstr("S   val : ");
		ft_putnbr(s);
		ft_putchar('\n');
		if (parm[0] == 1)
			newidx += 1;
		else
			newidx += psize[0];
		ft_putstr("mod val : ");
		ft_putnbr(s % IDX_MOD);
		ft_putchar('\n');
		ans = ft_getmemval(cw, pc->index + (s % IDX_MOD), psize[2]);
		ft_putstr("Ans val : ");
		ft_putnbr(ans);
		ft_putchar('\n');
		if (parm[1] == 1)
			newidx += 1;
		else
			newidx += psize[1];
		reg = ft_getmemval(cw, pc->index + newidx, 1);
		ft_putstr("Reg num : ");
		ft_putnbr(reg);
		ft_putchar('\n');
		pc->registers[reg] = (unsigned char*)ft_itoa_base(ans, 16);
	}
}

/*int main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 10;
	cw->mem[1] = 212;//100/228
	cw->mem[2] = 0;//5
	cw->mem[3] = 3;//0
	cw->mem[4] = 3;//4
	cw->mem[5] = 2;
	cw->mem[6] = 4;
	cw->mem[7] = 84;
	cw->mem[8] = 2;
	cw->mem[9] = 3;//2
	cw->mem[10] = 4;//up..
	cw->mem[11] = 0;
	cw->mem[12] = 0;*/
/*	cw->mem[13] = 2;
	cw->mem[14] = 3;//..here
	cw->mem[15] = 4;*/
/*	cw->mem[19] = 30;
	//cw->mem[13] = 4;
	pc->index = 0;

	ft_print_bits(cw, 0, 20);
	pc->registers[0] = (unsigned char*)"-1";
	pc->registers[1] = (unsigned char*)"0";
	pc->registers[2] = (unsigned char*)"2";
	pc->registers[3] = (unsigned char*)"3";
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
}*/

