# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-agr <jde-agr@student.wethinkcode.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 17:28:22 by tpatter           #+#    #+#              #
#    Updated: 2018/09/18 11:50:53 by jde-agr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
SRCDIR		=	srcs/
SRC			=	ft_add.c\
				ft_fork.c\
				ft_getparam.c\
				ft_itoa_base.c\
				ft_lld.c\
				ft_read_player.c\
				ft_sub.c\
				cwmain.c\
				ft_aff.c\
				ft_getdir.c\
				ft_getregval.c\
				ft_ld.c\
				ft_or.c\
				ft_st.c\
				ft_verify_eb.c\
				ft_and.c\
				ft_getind.c\
				ft_hextodec.c\
				ft_ldi.c\
				ft_sti.c\
				ft_xor.c\
				ft_hex_to_bin.c\
				ft_dec_to_hex.c\
				ft_docommand.c\
				ft_getmemval.c\
				ft_inittable.c\
				ft_live.c\
				ft_print_reg.c\
				ft_strinreg.c\
				ft_zjmp.c\
				init.c\
				ft_print_bits.c\
				ft_set_reg.c\
				ft_free_reg.c\
				ft_lfork.c\
				ft_dump.c\
				ft_getargs.c\
				ft_executepcs.c\
				ft_cull.c\
				ft_genpc.c\
				ft_print_player_data.c\
				ft_init_player_list.c\
				ft_crfirstpl.c\
				ft_store_player_info.c\
				ft_store_player.c\
				ft_file_size.c\
				ft_count_players.c\
				ft_read_error_msg.c\
				ft_viz.c
SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ			=	$(SRC:%.c=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	includes/
CFLAGS		=	
CC			=	gcc
LIBDIR		=	libft/
LIB			=	$(LIBDIR)libft.a
LIBHEAD		=	$(LIBDIR)includes/
LIBLINK		=	-L $(LIBDIR) -l ft -lncurses
INCLUDES	=	-I $(HEADER) -I $(LIBHEAD)

all: $(NAME)

$(NAME): $(OBJPATH) $(LIB)
	$(CC) -o $(NAME) $(OBJPATH) $(LIBLINK) $(INCLUDES) $(CFLAGS)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJPATH)
	make -C $(LIBDIR) clean

fclean:	clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all

neat: all clean
