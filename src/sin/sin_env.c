/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:42:03 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/27 15:21:17 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			*status(void)
{
	static int	status = 0;

	return (&status);
}

char		***env(void)
{
	static char	**env = NULL;

	return (&env);
}

t_termsize	*ft_termsize(void)
{
	static t_termsize	new;
	struct winsize		w;

	ioctl(0, TIOCGWINSZ, &w);
	new.col = w.ws_col;
	new.row = w.ws_row;
	return (&new);
}
