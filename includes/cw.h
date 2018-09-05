/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <tpatter@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:30:44 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 15:44:59 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "libft.h"
# include "op.h"

/*typedef	struct	s_cornfield //playfield
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
}				t_corn;*/

typedef struct		s_cw
{
	t_list			*playerlist;
	int 			nbrplayers;
	t_list			*pclist;
	unsigned char	*mem;
	unsigned int	cyclecounter;
}					t_cw;

typedef struct		s_pc
{
	int				index;
	unsigned int	idnbr;
	int				cr;
	unsigned char	**registers;
	unsigned char	carry;
}					t_pc;

typedef struct		s_player
{
	int				live;
	char			*name;
	char			*warcry;
	unsigned int	idnbr;
}					t_player;

unsigned char	*dec_to_hex(unsigned char n);
void			ft_initcw(t_cw *cw);
void			ft_docommand(t_cw *cw, t_pc *pc);

#endif
