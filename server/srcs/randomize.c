/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 17:54:20 by psprawka          #+#    #+#             */
/*   Updated: 2018/05/31 16:22:00 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy_server.h"

/*	There are 4 directions:
**	NORTH	1
**	EAST	2
**	SOUTH	3
**	WEST	4
*/


int rand_direction(void)
{
	srand(time(0));
	return (rand() % (4 - 1 + 1) + 1); 
}

int rand_position(t_map *map)
{
	int max_position;

	srand(time(0));
	max_position = map->x * map->y;
	return (rand() % (max_position - 1 + 1) + 1);
}
