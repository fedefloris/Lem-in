/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ant.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		move_ant(t_ant *ant, t_farm *farm, t_list *path)
{
	t_room	*room;
	t_room	*next_room;

	if (!(ant->room))
		ant->room = farm->start;
	while (path->next)
	{
		room = (t_room*)(path->content);
		next_room = (t_room*)(path->next->content);
		if (ant->room == room &&
			(next_room->available || next_room == farm->end))
		{
			ant->room->available = 1;
			ant->room = next_room;
			ant->room->available = 0;
			return (1);
		}
		path = path->next;
	}
	return (0);
}
