/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:47:29 by cking             #+#    #+#             */
/*   Updated: 2018/09/14 13:31:08 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

void	ft_add(t_cw *cw, t_pc *pc)
{
	int				newidx;
	int				num;
	int				r1;
	int				r2;
	int				r3;
	//unsigned char	*ans;
	if (!pc->cr)
		pc->cr = cw->op_tab[4].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		pc->cr = cw->op_tab[4].ctc; //cycles to complete this
		newidx = 0; //beginning of current cmd
		num = 0;
		if (ft_verify_eb(cw, pc)) //valid eb
		{
			newidx += 2; //need to work on identifying registers!!
			r1 = ft_atoi_base(ft_itoa_base(cw->mem[pc->index + newidx], 10), 10);
			r2 = ft_atoi_base(ft_itoa_base(cw->mem[pc->index + newidx + 1],
			10), 10);
			r3 = ft_atoi_base(ft_itoa_base(cw->mem[pc->index + newidx + 2],
			10), 10);
			num = ft_atoi_base((char*)pc->registers[r1 - 1], 10) +
			ft_atoi_base((char*)pc->registers[r2 - 1], 10);
			ft_putnbr(num);
			ft_putchar('\n');
			pc->registers[r3 - 1] = (unsigned char*)ft_itoa_base(num, 16);
			if (ft_atoi_base((char *)pc->registers[r3 - 1], 10) == 0) //carry
				pc->carry = 1;
		}
		pc->index += 5;
		pc->cyccomplete = 0;
	}
}

/*
** int main(void)
** {
** 	t_cw			*cw;
** 	t_pc			*pc;
**
** 	cw = (t_cw *)malloc(sizeof(t_cw));
** 	pc = (t_pc *)malloc(sizeof(t_pc));
** 	ft_inittable(cw);
** 	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
** 	cw->mem[0] = 4;
** 	cw->mem[1] = 84;
** 	cw->mem[2] = 1;
** 	cw->mem[3] = 3;
** 	cw->mem[4] = 16;
** 	cw->mem[15] = 0;
** 	//cw->mem[5] = 'B';
** 	//cw->mem[6] = 2;
** 	pc->index = 0;
**
** 	ft_print_bits(cw, 0, 5);
** 	pc->registers[0] = (unsigned char*)"3";
** 	pc->registers[1] = (unsigned char*)"2";
** 	pc->registers[2] = (unsigned char*)"23";
** 	pc->registers[3] = (unsigned char*)"2";
** 	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
** 	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
** 	ft_putchar('\n');
** 	ft_add(cw, pc);
** 	ft_putstr((char*)pc->registers[15]); //prints hex value
** 	ft_putchar('\n');
** 	ft_putnbr(pc->carry);
** 	//ft_ld(cw, pc);
** }
*/
