/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 13:38:54 by avan-ni           #+#    #+#             */
/*   Updated: 2018/09/13 13:58:15 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cw.h"
#include "op.h"
#include "fcntl.h"
#include <stdio.h>

void ft_read_error_msg(int flag, char *file)
{
	if (flag == 1)
	{
		ft_putstr("Error opening file: ");
		ft_putstr(file);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("Error reading from file: ");
		ft_putstr(file);
		ft_putchar('\n');
	}
}

int ft_file_size(char *file) // Count bytes to malloc for
{
	int i;
	int fd;
	int ret;
	unsigned char c;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_read_error_msg(1, file);
		return (0);
	}
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			i++;
		else if (ret == -1)
			ft_read_error_msg(2, file);
		if (ret < 1)
			break;
	}
	close(fd);
	return (i);
}

void ft_store_player(t_cw *cw, char *info, int pos, int incr)
{
	int i;
	t_list *tmp;

	i = -1;
	tmp = cw->playerlist;
	while (++i < incr)
		tmp = tmp->next;
	((t_player *)(tmp->content))->magic_num = ft_strndup(info, 8);
	((t_player *)(tmp->content))->name = ft_strnew_del((info + 8), '\0');
}

/*
void	ft_store_player(t_cw *cw, char *file, int pos, int player)
{
	int				i;
	int				fd;
	int				ret;
	unsigned char	c;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_read_error_msg(1, file);
		return ;
	}
	i = pos;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)// && i < (pos + (MEM_SIZE / 4)))
			cw->mem[i++] = c;
		else if (ret == -1)
			ft_read_error_msg(2, file);
		if (ret < 1)
			break ;
	}
	close(fd);
}
*/

int ft_count_players(char **players)
{
	int i;

	i = 1;
	while (players[i])
		i++;
	return (i - 1);
}

unsigned char *ft_store_player_info(char *file, int size) // Store player file info into temp char **
{
	int fd;
	int i;
	int ret;
	unsigned char c;
	unsigned char *str;

	str = (unsigned char *)malloc(sizeof(unsigned char) * (size));
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_read_error_msg(1, file);
		return (NULL);
	}
	i = 0;
	while (1)
	{
		ret = read(fd, &c, 1);
		if (ret == 1)
			str[i++] = c;
		else if (ret == -1)
			ft_read_error_msg(2, file);
		if (ret < 1)
			break;
	}
	close(fd);
	return (str);
}

void ft_crfirstpl(t_cw *cw) // initialise first player data
{
	t_player *player;

	cw->playerlist = (t_list *)malloc(sizeof(t_list));
	player = (t_player *)malloc(sizeof(t_player));
	player->live = 0;
	player->name = NULL;
	player->warcry = NULL;
	player->idnbr = 0;
	player->magic_num = NULL;
	cw->playerlist->content = player;
	cw->playerlist->next = NULL;
	cw->playerlist->content_size = sizeof(t_player);
}

void ft_init_player_list(t_cw *cw, int npl) //	Create player list and initialise
{
	int i;
	t_list *tmplist;
	t_player *tmpplayer;

	if (!cw->playerlist)
		ft_crfirstpl(cw);
	i = 1;
	while (i < npl)
	{
		tmpplayer = (t_player *)malloc(sizeof(t_player));
		tmpplayer->live = 0;
		tmpplayer->name = NULL;
		tmpplayer->warcry = NULL;
		tmpplayer->idnbr = 0;
		tmpplayer->magic_num = NULL;
		tmplist = (t_list *)malloc(sizeof(t_list));
		tmplist->content = tmpplayer;
		tmplist->content_size = sizeof(t_player);
		ft_lstadd(&(cw->playerlist), tmplist);
		i++;
	}
}

int ft_read_player(t_cw *cw, char **players)
{
	int mem;
	int npl;
	int i;
	char *str;

	npl = ft_count_players(players);
	ft_init_player_list(cw, npl);
	mem = (MEM_SIZE) / (npl);
	i = 1;
	while (i <= npl)
	{
		str = ft_store_player_info(players[i], ft_file_size(players[i]));
		ft_store_player(cw, str, mem * (i - 1), npl - i);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_cw *cw;

	argc = 0;
	cw = (t_cw *)malloc(sizeof(t_cw));
	ft_inittable(cw);
	init_struct(cw);
	ft_print_bits(cw, 0, MEM_SIZE);
	ft_read_player(cw, argv);
	ft_print_bits(cw, 0, MEM_SIZE);
	return (0);
}