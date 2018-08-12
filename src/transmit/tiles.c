/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:09:02 by nkouris           #+#    #+#             */
/*   Updated: 2018/08/11 18:12:32 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include "graphics.h"
#include "board.h"
#include "communication.h"
#include "transmit.h"

static int32_t	all(void *trans);
static int32_t	mapsize(void *trans);

__attribute__((constructor)) void construct_transmit_tiles(void)
{
	transmit.tiles.all = &all;
	transmit.tiles.mapsize = &mapsize;
}

static int32_t		mapsize(void *trans)
{
	char	*num;

	num = ft_itoa(board.data.x + 1);
	server.sendbuf = strcat(server.sendbuf, "msz ");
	server.sendbuf = strcat(server.sendbuf, num);
	server.sendbuf = strcat(server.sendbuf, " ");
	num = ft_itoa(board.data.y + 1);
	server.sendbuf = strcat(server.sendbuf, num);
	server.sendbuf = strcat(server.sendbuf, "\n");
	if (transmit.flag == GRAPHICAL)
		communication.graphical(trans, server.sendbuf);
	else if (transmit.flag == VEHICLE)
		communication.vehicles(trans, server.sendbuf, 1);
	bzero(server.sendbuf, server.nsend);
	return (EXIT_SUCCESS);
}

static int32_t all(void *trans)
{
	int32_t x;
	int32_t y;
	char *num;

	printf("BEGIN\ttransmit.tiles.all()\n");
	x = 0;
	while (x <= board.data.x)
	{
		y = 0;
		while (y <= board.data.y)
		{
			server.sendbuf = strcat(server.sendbuf, "bct ");
			num = ft_itoa(x);
			server.sendbuf = strcat(server.sendbuf, num);
			server.sendbuf = strcat(server.sendbuf, " ");
			num = ft_itoa(y);
			server.sendbuf = strcat(server.sendbuf, num);
			server.sendbuf = strcat(server.sendbuf, " ");
			num = ft_itoa((board.data.tiles[x]).column[y].state);
			server.sendbuf = strcat(server.sendbuf, num);
			server.sendbuf = strcat(server.sendbuf, "\n");
			if (transmit.flag == GRAPHICAL)
			{
				if (communication.graphical(trans, server.sendbuf) == EXIT_FAILURE)
					return (EXIT_FAILURE);
			}
			else if (transmit.flag == VEHICLE)
			{
				if (communication.vehicles(trans, server.sendbuf, 1) == EXIT_FAILURE)
				{
					printf("exit transmit all tiles\n");
					return (EXIT_FAILURE);
				}
			}
			bzero(server.sendbuf, server.nsend);
			y++;
		}
		x++;
	}
	bzero(server.sendbuf, server.nsend);
	printf("END\ttransmit.tiles.all()\n");
	return (EXIT_SUCCESS);
}
