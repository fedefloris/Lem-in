/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_rooms_distance.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_queue(t_farm *farm)
{
	t_list	*queue;
	t_list	*new;
	t_list	*lst;

	queue = NULL;
	lst = farm->rooms;
	while (lst)
	{
		if (!(new = ft_lstcpy(lst->content, sizeof(t_room))))
		{
			ft_lstdel(&queue, NULL);
			return (NULL);
		}
		ft_lstappend(&queue, new);
		lst = lst->next;
	}
	return (queue);
}

static t_room	*get_lowest_distance(t_list *rooms)
{
	t_room	*room;
	int		min;

	room = (t_room*)(rooms->content);
	min = room->dist;
	rooms = rooms->next;
	while (rooms)
	{
		if (((t_room*)(rooms->content))->dist < min)
		{
			room = (t_room*)(rooms->content);
			min = room->dist;
		}
		rooms = rooms->next;
	}
	return (room);
}

static void		update_distances(t_farm *farm, t_room *room)
{
	t_list	*links;
	t_link	*link;
	t_room	*to;

	links = farm->links;
	while (links)
	{
		link = (t_link*)(links->content);
		if (link->to == room)
			to = link->from;
		else if (link->from == room)
			to = link->to;
		else
			to = NULL;
		if (to && to != farm->start && to->dist > room->dist + 1)
		{
			to->dist = room->dist + 1;
			to->prev = room;
		}
		links = links->next;
	}
}

int				run_dijkstra(t_farm *farm)
{
	t_room	*closest;
	t_list	*queue;

	farm->start->dist = 0;
	if (!(queue = get_queue(farm)))
		return (0);
	while (queue)
	{
		closest = get_lowest_distance(queue);
		ft_lstremove(&queue, closest, NULL);
		update_distances(farm, closest);
	}
	return (farm->end->dist != INT_MAX - 1);
}
