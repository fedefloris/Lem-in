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

static int	add_to_rooms(t_room *room, t_farm *farm)
{
	t_list	*new;

	if (!(new = ft_lstcpy(room, sizeof(t_room))))
	{
		free_room(room, sizeof(t_room));
		return (0);
	}
	ft_lstappend(&(farm->rooms), new);
	return (1);
}

int			parse_room(t_list **input, t_farm *farm)
{
	int		command;
	t_room	*room;

	if ((command = get_command(*input)) != -1 &&
		((command == START_COMMAND && !(farm->start)) ||
		(command == END_COMMAND && !(farm->end))))
		*input = (*input)->next;
	if (is_link(*input))
		return (1);
	if (!(*input) || !(room = parse_room_info((char*)((*input)->content)))
		|| !add_to_rooms(room, farm) ||
		(command == START_COMMAND && farm->start) ||
		(command == END_COMMAND && farm->end))
		return (0);
	if (command == START_COMMAND && !(farm->start))
		farm->start = room;
	else if (command == END_COMMAND && !(farm->end))
		farm->end = room;
	if (find_room_info(farm, room))
		return (0);
	return (1);
}
