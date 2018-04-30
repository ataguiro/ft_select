/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sin_select                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataguiro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:04:27 by ataguiro          #+#    #+#             */
/*   Updated: 2017/01/26 16:07:50 by ataguiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_choice	*choice(void)
{
	static t_choice	choice;

	return (&choice);
}

char		**search(void)
{
	static char	*search = NULL;

	return (&search);
}
