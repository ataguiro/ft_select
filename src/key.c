/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 12:44:58 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/28 12:39:08 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int	match(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (*s1 == 0 && *s2 == 0)
		return (1);
	if (*s1 != 0 && *s2 == '*')
		return (match(s1, s2 + 1) || (match(s1 + 1, s2)));
	if (*s1 == 0 && *s2 == '*')
		return (match(s1, s2 + 1));
	if (*s2 == *s1)
		return (match(s1 + 1, s2 + 1));
	return (0);
}

static void	dynamic_search(char c)
{
	int		size;
	int		i;
	char	*pattern;

	i = 1;
	size = *search() ? ft_strlen(*search()) : 0;
	size < 32 && (*env())[1] ? (*search())[size] = c : 0;
	pattern = ft_strjoin(*search(), "*");
	while ((*env())[i])
	{
		if (match((*env())[i], pattern))
		{
			choice()->current = i;
			break ;
		}
		i++;
	}
	ft_strdel(&pattern);
}

void		key_dump(int key)
{
	if (key == CODE_RIGHT && (*env())[1] && (*env())[2])
		code_right();
	else if (key == CODE_LEFT)
		code_left();
	else if (key == CODE_UP)
		code_up();
	else if (key == CODE_DOWN)
		code_down();
	else if (key == CODE_SPACE && (*env())[1])
		code_space();
	else if (key == CODE_BACK || key == CODE_DEL)
		code_backspace();
	else if (key == CODE_RETURN && (*env())[1])
		code_return();
}

int			key_get(void)
{
	char	c[4];

	ft_raw_mode();
	read(0, c, 3);
	if (c[0] == '\x9' || c[0] == '\x4' || c[0] == '\x18' ||
			c[0] == '\x15' || c[0] == '\x17' ||
			c[0] == '\x7f' || c[0] == '\xa' || c[0] == '\x20')
		return (get_basics(c[0]));
	if (c[0] == '\x1b')
	{
		if (!c[1])
			return (CODE_ESCAPE);
		else
			return (get_x1b(c));
	}
	dynamic_search(c[0]);
	return (-2);
}
