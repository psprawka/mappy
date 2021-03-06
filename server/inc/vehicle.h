/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vehicle.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkouris <nkouris@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/02 15:30:42 by nkouris           #+#    #+#             */
/*   Updated: 2018/08/10 17:10:07 by nkouris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

typedef struct		s_destination
{
	int32_t			x;
	int32_t			y;
}					t_destination;

typedef	struct		s_location
{
	int32_t			x;
	int32_t			y;
	int8_t			orientation;
}					t_location;

typedef struct		s_vehicle
{
	t_dblist		container;
	t_dblist		tilecontainer;
	t_dblist		commscontainer;
	int32_t			c_fd;
	uint64_t		vehicle_id;
	int8_t			conn_attempts;
	t_location		location;
	t_timeval		alarm;
	t_queue			pending;
	t_destination	goal;
	char			*message;
}					t_vehicle;

typedef struct		s_vehiclepool
{
	t_queue			*data;
	int32_t			(*new)(void);
	t_dblist		*(*pop)(void);
	void			(*add)(t_vehicle *add);
}					t_vehiclepool;

typedef struct		s_vehicleplace
{
	void			(*onboard)(t_vehicle *);
	void			(*goal)(t_vehicle *);
}					t_vehicleplace;

typedef struct		s_vehicles
{
	t_vehiclepool	pool;
	t_vehicleplace	place;
	t_queue			data;
	int32_t			(*new)(int32_t);
	int32_t			(*command)(t_vehicle *);
}					t_vehicles;

t_vehicles			vehicle;

#endif
