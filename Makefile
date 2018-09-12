# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 17:28:22 by tpatter           #+#    #+#              #
#    Updated: 2018/09/11 16:25:18 by avan-ni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	corewar
SRCDIR		=	srcs/
SRC			=	init.c main.c ft_itoa_base.c\
				ft_read_player.c\
				ft_inittable.c\
				dec_to_hex.c\
				ft_getparam.c\
				ft_print_bits.c
SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ			=	$(SRC:%.c=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	includes/
CFLAGS		=	-Wall -Werror -Wextra
CC			=	gcc
LIBDIR		=	libft/
LIB			=	$(LIBDIR)libft.a
LIBHEAD		=	$(LIBDIR)includes/
LIBLINK		=	-L $(LIBDIR) -l ft
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
