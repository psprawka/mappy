/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 18:03:33 by psprawka          #+#    #+#             */
/*   Updated: 2018/06/02 00:50:46 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

int		command_kick(t_player *player, t_server *serv)
{
	int	i = 0;
	
	while (i < FD_SETSIZE)
	{
		if (!serv->players[i] && ++i)
			continue;
		
		if (serv->players[i]->position == player->position && serv->players[i]->fd != player->fd)
			command_advance(player, serv);
		i++;
	}
	return (1);
}
