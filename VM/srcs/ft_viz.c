#include "cw.h"

/*
** Manages the printing of registers
** j and k used to track position withing the MEMORY window
** gets values from registers and prints them out accordingly
*/

void	regs(WINDOW *win, t_pc *pc)
{
	int i;
	int j;

	i = 0;
	//pc = (t_pc*)malloc(sizeof(t_pc));
	//pc->registers = (unsigned char**)malloc(sizeof(char*) * REG_NUMBER);
	while (i < REG_NUMBER)
	{
		j = 2;
		//pc->registers[i] = (unsigned char*)ft_strnew(REG_SIZE);
		//pc->registers[i] = (unsigned char*)"0";
		mvwprintw(win, i + 2, j++, "Register %i", i + 1);
		mvwprintw(win, i + 2, 30, "%u", ft_getregval(pc, i));
		i++;
	}
	//wrefresh(win);
}

/*
** controls the REGISTERS window...
*/

void	print_reg(WINDOW *win, t_pc *pc)
{
	wattron(win, COLOR_PAIR(3));
	mvwprintw(win, 0, 17, "  REGISTERS  ");
	wattroff(win, COLOR_PAIR(3));
	regs(win, pc);
	//wrefresh(win);
}

/*
** ft_assign_col highlights any changes made to memory
*/

void	ft_assign_col(WINDOW *win, t_cw *cw, int i)
{
	if (cw->memp[i] >= 5)
	{
		wattron(win, COLOR_PAIR((cw->memp[i] % 5) + 1 + 5));
		cw->memp[i] -= 5;
	}
	else
		wattron(win, COLOR_PAIR((cw->memp[i] % 5) + 1));
}

/*
** ft_pc_col keeps track of which process is currently being executed
*/

void	ft_pc_col(WINDOW *win, t_cw *cw, int i)
{
	t_list *tmp;

	tmp = cw->pclist;
	while (tmp)
	{
		if (i == ((t_pc*)tmp->content)->index)//((t_pc*)cw->pclist->content)->index)
		{
			wattron(win, COLOR_PAIR((cw->memp[i] % 5) + 1 + 10));
			break ;
		}			
		tmp = tmp->next;
	}
	//else if (i == ((t_pc*)cw->pclist->next)->index)
	//	wattron(win, COLOR_PAIR(12));
}

int		ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}

void	ft_abs_memp(t_cw *cw)
{
	int i;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < MEM_SIZE)
	{
		tmp = ft_abs(cw->memp[i]);
		cw->memp[i] = tmp;
		i++;
	}
}

/*
** Manages the printing of memory
** j and k used to track position withing the MEMORY window
** siimilar algorithm to print_bits
*/

void	mem_print(WINDOW *win, t_cw *cw, int n)
{
	int	i;
	int j;
	int k;

	i = -1;
	j = 1;
	k = 2;
	ft_abs_memp(cw);

	WINDOW *win2 = newwin(100, 105, 22, 205);
	while (++i < n)
	{
		if ((i % 70) == 0)
			j++;
		mvwprintw(win2, j, i % 70, "%i", cw->memp[i]);
	}
	wrefresh(win2);
	WINDOW *win3 = newwin(10, 30, 75, 5);
	mvwprintw(win3, 1, 2, "Total Cycles : %i", cw->cyclebase);
	mvwprintw(win3, 2, 2, "Cycle Count : %i", cw->cyclecounter);
	mvwprintw(win3, 3, 2, "Live Status : %i", ((t_pc*)cw->pclist->content)->live);
	mvwprintw(win3, 4, 2, "Nbr of Lives : %i", cw->nbr_live_calls);
	wrefresh(win3);
	i = 0;
	j = 1;
	while (i < n)
	{
		ft_assign_col(win, cw, i);
		ft_pc_col(win, cw, i);
		//mvwprintw(win, 10, 10, "%i", cw->memp[i]);
		(cw->mem[i] < 16) ? mvwprintw(win, j, k++, "0") : k;
		if (cw->mem[i])
		{
			mvwprintw(win, j, k++, ft_itoa_base(cw->mem[i], 16));
			(cw->mem[i] > 15) ? k++ : k;
		}
		else
			mvwprintw(win, j, k++, "0");
		i++;
		(i <= n) ? mvwprintw(win, j, k++, " ") : k;
		((i % 64 == 0) && (j++)) ? k = 2 : k;
	}
}

/*
** controls the MEMORY window...
** additionally checking colour implementation in seperate windows
*/

void	print_mem(WINDOW *win, t_cw *cw)
{
	wattron(win, COLOR_PAIR(2));
	mvwprintw(win, 0, 91, "  MEMORY  ");
	wattroff(win, COLOR_PAIR(2));
	mem_print(win, cw, MEM_SIZE);
	//wattroff(win, COLOR_PAIR(2));
	//wrefresh(win);
}

/*
** defines the layout for both the MEMORY and REGISTERS windows
** removes cursor and initiates possible colour pairs
*/

void	ft_layout(WINDOW *win, WINDOW *win2)
{
	curs_set(0);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_BLUE);
	init_pair(8, COLOR_YELLOW, COLOR_BLUE);
	init_pair(9, COLOR_GREEN, COLOR_BLUE);
	init_pair(10, COLOR_MAGENTA, COLOR_BLUE);
	init_pair(11, COLOR_WHITE, COLOR_BLACK); // Default
	init_pair(12, COLOR_BLACK, COLOR_RED);
	init_pair(13, COLOR_BLACK, COLOR_YELLOW);
	init_pair(14, COLOR_BLACK, COLOR_GREEN);
	init_pair(15, COLOR_BLACK, COLOR_MAGENTA);
	box(win, 0, 0);//window, char l&r, char t&b
	box(win2, 0, 0);
	//wrefresh(win);
	//wrefresh(win2);
}

/*
** Defines the variables for the layout of the screen
** Creates two windows win for MEMORY and win2 for REGISTERS
** Create boxes to seperate the two windows within the terminal
** calls print_mem and print_reg functions
** awaits user to enter any key to exit and then closes
*/

void	ft_viz2(t_cw *cw, t_pc *pc, WINDOW *win, WINDOW *win2)
{
	int	i;
	t_list	*tmp;
	// WINDOW *win;
	// WINDOW *win2;

	//win = newwin(66, 195, 2, 5);//height, width, start y, start x
	//win2 = newwin(20, 50, 2, 205);
	//ft_layout(win, win2);
	//int c = getchar();
	noecho();
	print_mem(win, cw);
	wrefresh(win);
	print_reg(win2, cw->pcdisplay);
	wrefresh(win2);
	//usleep(100000);
	int c = getchar();//usleep(5000000);
	while (c == '.' || c == ',')
	{
		if (c == '.')
		{
			i = 0;
			cw->displaycount++;
			tmp = cw->pclist;
			while (i < cw->displaycount && tmp->next)
			{
				tmp = tmp->next;
				i++;
			}
			cw->pcdisplay = (t_pc*)tmp->content;
		}
		else if (c == ',')
		{
			i = 0;
			if (cw->displaycount > 0)
			cw->displaycount--;
			tmp = cw->pclist;
			while (i < cw->displaycount && tmp->next)
			{
				tmp = tmp->next;
				i++;
			}
			cw->pcdisplay = (t_pc*)tmp->content;
		}
		tmp = cw->playerlist;
		while (tmp)
		{
			mvwprintw(win2, 1, 2, "						");
			if (((t_player*)tmp->content)->idnbr == cw->pcdisplay->idnbr)
			{
				mvwprintw(win2, 1, 2, "Player %s", ((t_player*)tmp->content)->name);
				break ;
			}				
			tmp = tmp->next;
		}
		print_reg(win2, cw->pcdisplay);
		wrefresh(win2);
		wclear(win2);
		c = getchar();
	}
}

void	ft_viz(t_cw *cw, t_pc *pc, WINDOW *win, WINDOW *win2)
{
	//initscr();
	//win = newwin(66, 195, 2, 5);//height, width, start y, start x
	//win2 = newwin(20, 50, 2, 205);
	ft_layout(win, win2);
	ft_viz2(cw, pc, win, win2);

	//endwin();
}