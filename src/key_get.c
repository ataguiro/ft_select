/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 13:06:57 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 13:11:40 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_basics(char c)
{
	if (c == '\x20')
		return (CODE_SPACE);
	if (c == '\x7f')
		return (CODE_BACK);
	if (c == '\xa')
		return (CODE_RETURN);
	return (-42);
}

int		get_x1b(char *c)
{
	if (c[1] == '\x5b')
	{
		if (c[2] == '\x41')
			return (CODE_UP);
		if (c[2] == '\x42')
			return (CODE_DOWN);
		if (c[2] == '\x43')
			return (CODE_RIGHT);
		if (c[2] == '\x44')
			return (CODE_LEFT);
		if (c[2] == '\x48')
			return (CODE_HOME);
		if (c[2] == '\x46')
			return (CODE_END);
		if (c[2] == '3')
			return (CODE_DEL);
	}
	return (-42);
}
