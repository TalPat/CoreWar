# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cking <cking@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 17:28:22 by tpatter           #+#    #+#              #
#    Updated: 2018/09/28 13:35:17 by cking            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	asm
SRCDIR		=	srcs/
SRC			=	asmmain.c\
				ft_createfile.c\
				ft_append.c\
				ft_getindex.c\
				ft_buildeb.c\
				ft_trim.c\
				ft_file_size.c\
				ft_store_info.c\
				ft_get_args.c
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
