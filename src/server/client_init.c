/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 11:15:52 by nkouris           #+#    #+#             */
/*   Updated: 2018/06/02 16:22:11 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_server.h"
#include "communication.h"
#include "player.h"


int32_t			client_init(void)
{
	int32_t		ret;

	ret = EXIT_SUCCESS;
#ifdef DEBUG
	ft_printf("<--- CLIENT INIT --->\n");
#endif
	if (!(SRV_TEMP.purgatory[SRV_CLNT]))
	{
		if ((ret = communicate.toclient.welcome()) == EXIT_FAILURE)
			SRV_TEMP.purgatory[SRV_CLNT] = NOT_ACCEPTED;
	}
	else
	{
		if (player.islost())
			ret = player.add_toteam();
		else
		{
			ret = player.new();
			ret = player.add_toteam();
		}
	}
	return (ret);
}
