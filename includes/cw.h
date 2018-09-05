/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cking <cking@student.wethinkcode.co.za>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:30:44 by cking             #+#    #+#             */
/*   Updated: 2018/09/05 16:01:33 by cking            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "libft.h"
# include "op.h"

typedef struct		s_cw
{
	t_list			*playerlist;
	int				nbrplayers;
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

void			ft_initcw(t_cw *cw);
void			ft_docommand(t_cw *cw, t_pc *pc);
void			ft_live(t_cw *cw, t_pc *pc);
char			*hex_to_bin(char *hex);
unsigned char	*dec_to_hex(unsigned char n);

#endif
