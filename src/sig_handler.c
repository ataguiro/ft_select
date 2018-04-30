/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:44:40 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 13:48:05 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_handler(int signo)
{
	ft_default_mode();
	*status() = 0;
	if (signo == SIGWINCH)
	{
		ft_print_args();
		ft_raw_mode();
	}
	else
	{
		ft_putstr_fd("\033[H\033[J", 0);
		exit(signo);
	}
}
