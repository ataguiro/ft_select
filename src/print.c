/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:21:06 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/28 12:42:42 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		file_type(char *file)
{
	struct stat	info;

	stat(file, &info);
	if (S_ISREG(info.st_mode) && access(file, X_OK) == -1)
	{
		return (REG_FILE);
	}
	else if (S_ISDIR(info.st_mode) && access(file, F_OK) != -1)
	{
		return (IS_DIR);
	}
	else if (access(file, X_OK) != -1)
	{
		return (EXE_FILE);
	}
	else
	{
		return (NOT_A_FILE);
	}
}

static void		special_print(char *str, int i)
{
	if (file_type(str) == NOT_A_FILE)
		ft_putstr_fd("\033[2m", 0);
	else if (file_type(str) == IS_DIR)
		ft_putstr_fd("\033[1;36m", 0);
	else if (file_type(str) == EXE_FILE)
		ft_putstr_fd("\033[31m", 0);
	if (i == choice()->current)
		ft_putstr_fd("\033[4m", 0);
	if (choice()->selected[i])
		ft_putstr_fd("\033[7m", 0);
	ft_putstr_fd(str, 0);
	ft_putstr_fd("\033[0m", 0);
}

static void		print_header(void)
{
	ft_putstr_fd("\033[H\033[J", 0);
	ft_putstr_fd("\033[1;32m", 0);
	ft_putstr_fd("    ______                 __          __ \n", 0);
	ft_putstr_fd("   / __/ /_     ________  / /__  _____/ /_\n", 0);
	ft_putstr_fd("  / /_/ __/    / ___/ _ \\/ / _ \\/ ___/ __/\n", 0);
	ft_putstr_fd(" / __/ /_     (__  )  __/ /  __/ /__/ /_  \n", 0);
	ft_putstr_fd("/_/  \\__/____/____/\\___/_/\\___/\\___/\\__/  \n", 0);
	ft_putstr_fd("       /_____/    by ataguiro             \n", 0);
	ft_putstr_fd("\n\033[0m", 0);
}

static void		correct_print(void)
{
	move_right(ft_termsize()->col);
	move_down(ft_termsize()->row);
	if (*status() == 0)
	{
		*status() = 1;
		ft_print_args();
	}
}

void			ft_print_args(void)
{
	int		i;
	int		max;
	int		gr;

	signal(SIGWINCH, sig_handler);
	(i = 1) ? ft_default_mode() : 0;
	(*env())[i] ? max = get_max_len() : 0;
	print_header();
	while (*env() && (*env())[i])
	{
		if (!gr)
		{
			if (((i - 1) * (max)) * 2 > (int)ft_termsize()->col)
			{
				gr = i - 1;
				choice()->cols = gr;
				ft_putchar_fd('\n', 0);
			}
		}
		else if ((i - 1) % gr == 0)
			ft_putchar_fd('\n', 0);
		special_print((*env())[i], i);
		print_spaces(max, (*env())[i++]);
	}
	correct_print();
}
