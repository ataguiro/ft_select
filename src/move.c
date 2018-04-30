/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:48:38 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/12 12:59:16 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	move_left(int x)
{
	if (!x)
		return ;
	ft_putstr_fd("\033[", 0);
	ft_putnbr_fd(x, 0);
	ft_putstr_fd("D", 0);
}

void	move_right(int x)
{
	if (!x)
		return ;
	ft_putstr_fd("\033[", 0);
	ft_putnbr_fd(x, 0);
	ft_putstr_fd("C", 0);
}

void	move_down(int x)
{
	if (!x)
		return ;
	ft_putstr_fd("\033[", 0);
	ft_putnbr_fd(x, 0);
	ft_putstr_fd("B", 0);
}

void	move_up(int x)
{
	if (!x)
		return ;
	ft_putstr_fd("\033[", 0);
	ft_putnbr_fd(x, 0);
	ft_putstr_fd("A", 0);
}
