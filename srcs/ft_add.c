#include "cw.h"

void	ft_add(t_cw *cw, t_pc *pc)
{
	int				newidx;
	unsigned char	*tmp;

	pc->cr = 10; //cycles to complete this
	newidx = 0; //beginning of current cmd
	if (ft_verify_eb(cw, pc)) //valid eb
	{
		newidx += 2;
		
	}
	pc->index++;
}