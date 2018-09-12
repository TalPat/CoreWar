/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 15:59:54 by cking             #+#    #+#             */
/*   Updated: 2018/09/12 15:59:56 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"

int	ft_hextodec(char *str);

void	ft_zjmp(t_cw *cw, t_pc *pc)
{
	int				newidx;

	pc->cr = cw->op_tab[9].ctc; //cycles to complete this
	newidx = 0; //beginning of current cmd
	if (pc->carry == 1)
        newidx = ft_getdir(cw, pc->index + 1);
	else
		newidx = DIR_SIZE + 1;
	pc->index += newidx;
}

// int main(void)
// {
// 	t_cw			*cw;
// 	t_pc			*pc;

// 	cw = (t_cw *)malloc(sizeof(t_cw));
// 	ft_inittable(cw);
// 	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
// 	cw->mem[0] = 9;
// 	cw->mem[1] = 255;
// 	cw->mem[2] = 255;
// 	cw->mem[3] = 255;
// 	cw->mem[4] = 255;
// 	cw->mem[15] = 0;
// 	//cw->mem[5] = 'B';
// 	//cw->mem[6] = 2;
// 	pc->index = 0;

// 	ft_print_bits(cw, 0, 5);
// 	pc->registers[0] = (unsigned char*)"3";
// 	pc->registers[1] = (unsigned char*)"2";
// 	pc->registers[2] = (unsigned char*)"23";
// 	pc->registers[3] = (unsigned char*)"2";
// 	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
// 	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
// 	ft_putchar('\n');
//     pc->carry = 0;
// 	ft_zjmp(cw, pc);
// 	//ft_putstr((char*)pc->registers[15]); //prints hex value
//     ft_putnbr(pc->index);
// 	ft_putchar('\n');
// 	//ft_putnbr(pc->carry);
// 	//ft_ld(cw, pc);
// }
