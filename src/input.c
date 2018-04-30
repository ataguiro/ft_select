/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:44:25 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/28 12:29:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

void	init_choices(void)
{
	int	p;
	int	i;

	p = ft_tablen(*env());
	i = 0;
	choice()->selected = (int *)ft_memalloc(sizeof(int) * (p + 1));
	choice()->current = 1;
	choice()->cols = 0;
	*search() = ft_strnew(32);
	while (i <= p)
	{
		(choice()->selected)[i] = 0;
		i++;
	}
}

int		ft_input(void)
{
	int		key;

	key = 0;
	(*env())[1] && *env() ? init_choices() : 0;
	while (1)
	{
		ft_print_args();
		key = key_get();
		*status() = 0;
		if (key != -2)
		{
			ft_strdel(search());
			*search() = ft_strnew(32);
		}
		key_dump(key);
		if (key == -1)
		{
			ft_putstr_fd("\033[H\033[J", 0);
			ft_default_mode();
			return (-1);
		}
	}
}
