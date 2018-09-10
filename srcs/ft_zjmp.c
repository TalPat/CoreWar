#include "cw.h"

void	ft_zjmp(t_cw *cw, t_pc *pc)
{
	int				newidx;
	unsigned char	*ans;

	pc->cr = cw->op_tab[9].ctc; //cycles to complete this
	newidx = 0; //beginning of current cmd
	if (pc->carry == 1)
        newidx = ft_atoi_base(ft_itoa_base(cw->mem[pc->index + 1], 10), 10);
	else
		newidx = 3;
	ft_putstr("no..: ");
	ft_putnbr(newidx);
    ft_putchar('\n');

	pc->index += newidx;
}

int main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 9;
	cw->mem[1] = 255;
	cw->mem[2] = 255;
	cw->mem[3] = 3;
	cw->mem[4] = 7;
	cw->mem[15] = 0;
	//cw->mem[5] = 'B';
	//cw->mem[6] = 2;
	pc->index = 0;

	ft_print_bits(cw, 0, 5);
	pc->registers[0] = (unsigned char*)"3";
	pc->registers[1] = (unsigned char*)"2";
	pc->registers[2] = (unsigned char*)"23";
	pc->registers[3] = (unsigned char*)"2";
	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
	ft_putchar('\n');
    pc->carry = 1;
	ft_zjmp(cw, pc);
	//ft_putstr((char*)pc->registers[15]); //prints hex value
    ft_putnbr(pc->index);
	ft_putchar('\n');
	//ft_putnbr(pc->carry);
	//ft_ld(cw, pc);
}
