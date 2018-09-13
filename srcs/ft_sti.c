/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 11:47:51 by tpatter           #+#    #+#             */
/*   Updated: 2018/09/13 20:50:33 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cw.h"
#include <stdlib.h>

/*
**using an indirect val as param 2 uses value at index(4 bytes).
*/

void	ft_sti(t_cw *cw, t_pc *pc)
{
	int		*arr;
	int		newidx;
	int		i;
	int		src;
	int		sum;

	i = 0;
	if (!pc->cr)
		pc->cr = cw->op_tab[11].ctc;
	pc->cyccomplete++;
	if (pc->cr == pc->cyccomplete)
	{
		newidx = 1;
		if (ft_verify_eb(cw, pc))
		{
			arr = ft_getparam(cw->mem[pc->index + newidx]);
			newidx += 2;
			if (arr[1] == T_REG)
			{
				sum = ft_getregval(pc, cw->mem[pc->index + newidx]);
				newidx += 1;
			}
			else if (arr[1] == T_DIR)
			{
				sum = ft_getind(cw, pc->index + newidx);
				newidx += IND_SIZE;
			/**/ft_putendl(" ");
			/**/ft_putnbr(sum);
			/**/ft_putendl(" ");
			}
			else
			{
				sum = ft_getdir(cw, (pc->index + ft_getind(cw, (pc->index +
					newidx) % IDX_MOD)) % IDX_MOD);
				newidx += IND_SIZE;
			}
			if (arr[2] == T_REG)
			{
				sum += ft_getregval(pc, cw->mem[pc->index + newidx]);
				newidx += 1;
			}
			else
			{
				sum += ft_getind(cw, pc->index + newidx);
				newidx += IND_SIZE;
			/**/ft_putendl(" ");
			/**/ft_putnbr(sum);
			/**/ft_putendl(" ");
			}
			src = cw->mem[pc->index + 2];
			/**/ft_putendl(" ");
			/**/ft_putnbr(sum);
			/**/ft_putendl(" ");
			while (i < REG_SIZE)
			{
				cw->mem[(pc->index + (sum % IDX_MOD) + i) % MEM_SIZE] =
					pc->registers[src][i];
				i++;
			}
		}
		ft_putendl("HELLOOO");
		pc->index = (pc->index + newidx) % MEM_SIZE;
		pc->cr = 0;
		pc->cyccomplete = 0;
	}
}

/*int	main(void)
{
	t_cw *cw;
	t_pc *pc;

	pc = (t_pc*)malloc(sizeof(t_pc));
	cw = (t_cw*)malloc(sizeof(t_cw));
	ft_initcw(cw);
	pc->registers = (unsigned char**)malloc(sizeof(char*) * REG_SIZE);
	cw->mem[0] = 0xB;
	cw->mem[1] = 0x68;
	cw->mem[2] = 0x02;
	cw->mem[3] = 0xB;
	cw->mem[4] = 0xB;
	cw->mem[5] = 0xB;
	cw->mem[6] = 0xB;
	cw->mem[7] = 0xB;
	cw->mem[8] = 0xB;

}*/
