/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   codes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 10:33:11 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 13:15:19 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	code_down(void)
{
	int		i;

	i = 0;
	while (i++ < choice()->cols)
		(choice()->current)++;
	if (choice()->current >= (int)ft_tablen(*env()))
		choice()->current = 1;
}

void	code_right(void)
{
	(choice()->current)++;
	if (choice()->current >= (int)ft_tablen(*env()))
		choice()->current = choice()->current % ((int)ft_tablen(*env()) - 1);
}

void	code_left(void)
{
	(choice()->current)--;
	if (choice()->current < 1)
		choice()->current = (int)ft_tablen(*env()) - 1;
}

void	code_up(void)
{
	choice()->current -= choice()->cols;
	if (choice()->current < 1)
		choice()->current = (int)ft_tablen(*env()) - 1;
}
