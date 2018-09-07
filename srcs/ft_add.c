#include "cw.h"

void	ft_add(t_cw *cw, t_pc *pc)
{
	int				newidx;
	int				num;
	unsigned char	*ans;

	pc->cr = 10; //cycles to complete this
	newidx = 0; //beginning of current cmd
	num = 0;
	if (ft_verify_eb(cw, pc)) //valid eb
	{
		newidx += 2; //need to work on identifying registers!!
		//pc->registers[newidx + 2] = pc->registers[newidx] + pc->registers[newidx + 1];
		num = (ft_atoi_base((char*)pc->registers[newidx - 1], 10) + ft_atoi_base((char*)pc->registers[newidx], 10));
		ft_putnbr(num);
		ft_putchar('\n');
		pc->registers[newidx + 2] = (unsigned char*)ft_itoa_base(num, 16);
		ft_putstr((char*)pc->registers[newidx + 2]);
	}
	pc->index++;
}

int main(void)
{
	t_cw			*cw;
	t_pc			*pc;

	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	cw->mem = (unsigned char *)malloc(sizeof(unsigned char) * 7);
	cw->mem[0] = 4;
	cw->mem[1] = 84;
	cw->mem[2] = 1;
	cw->mem[3] = 2;
	cw->mem[4] = 3;
	//cw->mem[5] = 'B';
	//cw->mem[6] = 2;
	pc->index = 0;
	
	ft_print_bits(cw, 0, 5);
	pc->registers[1] = (unsigned char*)"12";
	pc->registers[2] = (unsigned char*)"-2";
	pc->registers[3] = (unsigned char*)"30";
	//pc->registers[2][0] = (unsigned char)ft_strdup("3");
	//pc->registers[2][1] = (unsigned char)ft_strdup("0");
	ft_putchar('\n');
	ft_add(cw, pc);
	ft_putstr((char*)pc->registers[4]);
	//ft_ld(cw, pc);
}