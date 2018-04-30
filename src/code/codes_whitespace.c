/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codes_whitespace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:36:26 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:33:22 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	check_last(int i, int tablen, int *selected)
{
	while (i <= tablen)
	{
		if (selected[i])
			return (1);
		i++;
	}
	return (0);
}

void		code_space(void)
{
	if (!(choice()->selected[choice()->current]))
		choice()->selected[choice()->current] = 1;
	else
		choice()->selected[choice()->current] = 0;
	if ((*env())[2])
		(choice()->current)++;
	if (choice()->current >= (int)ft_tablen(*env()))
		choice()->current = choice()->current % ((int)ft_tablen(*env()) - 1);
}

void		code_backspace(void)
{
	if (!(*env())[1])
	{
		ft_default_mode();
		ft_putstr_fd("\033[H\033[J", 0);
		exit(0);
	}
	ft_itabremove(&(choice()->selected), choice()->current, ft_tablen(*env()));
	ft_tabremove(env(), (*env())[choice()->current], NULL);
	if (choice()->current == (int)ft_tablen(*env()))
		(choice()->current)--;
}

void		code_return(void)
{
	int		i;
	int		tablen;

	i = 0;
	tablen = (int)ft_tablen(*env());
	ft_putstr_fd("\033[H\033[J", 0);
	while (i <= tablen)
	{
		if (choice()->selected[i])
		{
			ft_putstr((*env())[i]);
			if (check_last(i + 1, tablen, choice()->selected))
				ft_putchar(' ');
		}
		i++;
	}
	ft_default_mode();
	exit(0);
}
