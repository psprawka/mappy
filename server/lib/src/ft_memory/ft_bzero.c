/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 15:04:28 by nkouris           #+#    #+#             */
/*   Updated: 2017/09/28 23:51:55 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int		i;
	char				*t;

	t = (char*)s;
	i = 0;
	while (i++ < n)
	{
		*t = 0;
		t++;
	}
}
