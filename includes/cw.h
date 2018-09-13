/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cw.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpatter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 11:30:44 by cking             #+#    #+#             */
/*   Updated: 2018/09/13 16:50:24 by tpatter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CW_H
# define CW_H

# include "../libft/includes/libft.h"
# include "op.h"

typedef struct		s_op
{
	char			*name;
	int				argc;
	int				arg[4];
	int				op_code;
	int				ctc;
	char			*desc;
	int				eb;
	int				dunno;
}					t_op;

typedef struct		s_cw
{
	t_list			*playerlist;
	int				nbrplayers;
	t_list			*pclist;
	unsigned char	*mem;
	unsigned int	cyclecounter;
	t_op			op_tab[17];
	int				cycle2die;
	int				cycledelta;
	int				nbr_live_calls;
	int				options;
	int				gameover;
	int				dump;
	int				dumpno;
	int				error;
	int				visualiser;
}					t_cw;

typedef struct		s_pc
{
	int				index;
	unsigned int	idnbr;
	int				cr;
	int				cyccomplete;
	unsigned char	**registers;
	unsigned char	carry;
	unsigned char	live;
}					t_pc;

typedef struct		s_player
{
	int				live;
	char			*name;
	char			*warcry;
	unsigned int	idnbr;
	char			*magic_num;
	int				progsize;
}					t_player;

void			ft_initcw(t_cw *cw);
void			ft_docommand(t_cw *cw, t_pc *pc);
char			*hex_to_bin(char *hex);
unsigned char	*dec_to_hex(unsigned char n);
int				*ft_getparam(unsigned char c);
int				*ft_getparam_size(unsigned char c);
int				ft_verify_eb(t_cw *cw, t_pc *pc);
int				ft_getdir(t_cw *cw, int idx);
int				ft_getind(t_cw *cw, int idx);
void			ft_inittable(t_cw *cw);
void			ft_print_bits(t_cw *cw, int index, int n);
char			*ft_itoa_base(int value, int base);
void			ft_print_reg(t_pc *pc);
int				ft_getregval(t_pc *pc, int reg);
int				ft_hextodec(char *str);
void			init_struct(t_cw *cw);
int				ft_read_player(t_cw *cw, char **players);
void			ft_set_reg_reg(t_pc *pc, int reg_src, int reg_dst);
void			ft_set_reg_ind(t_cw *cw, t_pc *pc, int index, int reg_num);
void			ft_set_reg_dir(t_cw *cw, t_pc *pc, int index, int reg_num);
void			ft_llddir(t_cw *cw, t_pc *pc);
void			ft_lldind(t_cw *cw, t_pc *pc);
void			ft_strinreg(t_pc *pc, int regno, int val);
void			ft_free_reg(unsigned char **reg);
void			ft_live(t_cw *cw, t_pc *pc);
void			ft_ld(t_cw *cw, t_pc *pc);
void			ft_st(t_cw *cw, t_pc *pc);
void			ft_add(t_cw *cw, t_pc *pc);
void			ft_sub(t_cw *cw, t_pc *pc);
void			ft_and(t_cw *cw, t_pc *pc);
void			ft_or(t_cw *cw, t_pc *pc);
void			ft_xor(t_cw *cw, t_pc *pc);
void			ft_zjmp(t_cw *cw, t_pc *pc);
void			ft_ldi(t_cw *cw, t_pc *pc);
void			ft_sti(t_cw *cw, t_pc *pc);
void			ft_fork(t_cw *cw, t_pc *pc);
void			ft_lld(t_cw *cw, t_pc *pc);
void			ft_lldi(t_cw *cw, t_pc *pc);
void			ft_lfork(t_cw *cw, t_pc *pc);
void			ft_aff(t_cw *cw, t_pc *pc);
void			ft_dump(t_cw *cw);

#endif
