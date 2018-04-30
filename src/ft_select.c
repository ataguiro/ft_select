/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:57:49 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 15:57:52 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include <signal.h>

int		main(int ac, char **av)
{
	(void)ac;
	if (!isatty(STDIN_FILENO))
		exit(0);
	signal(SIGWINCH, sig_handler);
	signal(SIGINT, sig_handler);
	signal(SIGQUIT, sig_handler);
	signal(SIGKILL, sig_handler);
	signal(SIGTERM, sig_handler);
	signal(SIGABRT, sig_handler);
	signal(SIGHUP, sig_handler);
	*env() = ft_tabdup(av);
	ft_input();
}
