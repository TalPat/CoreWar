#include "cw.h"

void	ft_aff(t_cw *cw, t_pc *pc)
{
	int				newidx;
	int				reg;
	int				ans;

	pc->cr = cw->op_tab[16].ctc; //cycles to complete this
	newidx = 0; //beginning of current cmd
	if (ft_verify_eb(cw, pc))
	{
		newidx += 2;
		reg = cw->mem[pc->index + newidx] - 1;
		ft_putchar('\n');
		ans = ft_atoi_base((char*)pc->registers[reg], 10) % 256;
		ft_putchar(ans);
	}
	pc->index += newidx + 1;
}

int main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 16;
	cw->mem[1] = 64;
	cw->mem[2] = 3;
	cw->mem[3] = 255;
	cw->mem[4] = 255;
	cw->mem[15] = 0;
	//cw->mem[5] = 'B';
	//cw->mem[6] = 2;
	pc->index = 0;

	ft_print_bits(cw, 0, 5);
	pc->registers[0] = (unsigned char*)"3";
	pc->registers[1] = (unsigned char*)"2";
	pc->registers[2] = (unsigned char*)"1850";
	pc->registers[3] = (unsigned char*)"52";
	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
	ft_putchar('\n');
    pc->carry = 0;
	ft_aff(cw, pc);
	//ft_putstr((char*)pc->registers[15]); //prints hex value
    //ft_putnbr(pc->index);
	//ft_putchar('\n');
	//ft_putnbr(pc->carry);
	//ft_ld(cw, pc);
}
