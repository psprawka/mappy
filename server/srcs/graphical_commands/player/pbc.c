/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pbc.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:16:50 by tle-huu-          #+#    #+#             */
/*   Updated: 2018/06/19 04:21:31 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "zappy.h"

/*
** Hook function - not callable unless you pass it msg!
** Haven't decided if msg should be a stack or heap string.
*/

void	notify_broadcast(int fd, t_player *player, char *msg)
{
	int		len;

	strcpy(g_server.buff, "pbc ");
	strcat(g_server.buff, ft_itoa(player->fd));
	strcat(g_server.buff, " ");
	strcat(g_server.buff, msg + strlen("broadcast "));
	strcat(g_server.buff, "\n");
	len = strlen(g_server.buff);
	if (g_server.graphic_fd && send(fd, g_server.buff, len, 0) == -1)
		error(0, "Send [g: pbc]", true);
}
