/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   design.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:28:38 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 13:48:40 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int		get_max_len(void)
{
	size_t	max;
	int		i;

	i = 2;
	max = ft_strlen((*env())[1]);
	while (*env() && (*env())[i])
	{
		if (ft_strlen((*env())[i]) > max)
			max = ft_strlen((*env())[i]);
		i++;
	}
	return ((int)max);
}

void	print_spaces(int max, char *current)
{
	int diff;

	diff = max - ft_strlen(current);
	while ((diff + 5))
	{
		write(0, " ", 1);
		diff--;
	}
}
