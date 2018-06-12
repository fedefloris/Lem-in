/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	are_same_room_info(t_room *room1, t_room *room2)
{
	if (room1 && room1 != room2 &&
		(!ft_strcmp(room1->name, room2->name) ||
			(room1->x == room2->x && room1->y == room2->y)))
		return (1);
	return (0);
}

int			find_room_info(t_farm *farm, t_room *room)
{
	t_list	*rooms;

	rooms = farm->rooms;
	while (rooms)
	{
		if (are_same_room_info((t_room*)(rooms->content), room))
			return (1);
		rooms = rooms->next;
	}
	return (0);
}
