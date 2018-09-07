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
		newidx += 2;
		//pc->registers[newidx + 2] = pc->registers[newidx] + pc->registers[newidx + 1];
		num = (ft_atoi_base((char*)pc->registers[newidx], 10) + ft_atoi_base((char*)pc->registers[newidx + 1], 10));
		pc->registers[newidx + 2] = (unsigned char*)ft_itoa_base(num, 16);
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
	ft_putstr("hi\n");
	pc->registers[0][0] = (unsigned char)ft_strdup("1");
	ft_putstr("hi\n");
	pc->registers[0][1] = (unsigned char)ft_strdup("2");
	ft_putstr("hi\n");
	pc->registers[1] = 0;
	ft_putstr("hi\n");
	pc->registers[2][0] = (unsigned char)ft_strdup("3");
	pc->registers[2][1] = (unsigned char)ft_strdup("0");
	pc->registers[3] = 0;
	ft_putstr("hi\n");
	ft_add(cw, pc);
	//ft_ld(cw, pc);
}