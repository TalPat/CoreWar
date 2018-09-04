/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:30:44 by cking             #+#    #+#             */
/*   Updated: 2018/09/04 15:40:44 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "./libft/libft.h"
# include "./op.h"

typedef	struct	s_cornfield //playfield
{
	unsigned char	*field;
	t_corn			*pcs;
	int				cycles;

}				t_cornfield;

typedef struct	s_corn //pc...
{
	unsigned char 	*flags; //pop with default flags i.e. carry & live
	unsigned char	*p_num; //number of the player
	unsigned char   *reg;
	int				index;
}				t_corn;

/*typedef struct	s_cw
{
	unsigned char	*mem;
	unsigned char	*flags;
	t_list			*pclist;
}				t_cw;*/

typedef struct	s_pc
{
	int				pc;
	char			*name;
}				t_pc;

unsigned char	*dec_to_hex(unsigned char n);
void			ft_initcw(t_cw *cw);
void			ft_docommand(t_cw *cw, int pc);

#endif
