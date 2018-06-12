/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shortest_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list			*get_shortest_path(t_farm *farm)
{
	t_room	*room;
	t_list	*path;
	t_list	*new;

	if (!run_dijkstra(farm))
		return (NULL);
	path = NULL;
	room = farm->end;
	while (room)
	{
		if (!(new = ft_lstcpy(room, sizeof(t_room))))
		{
			ft_lstdel(&path, NULL);
			return (NULL);
		}
		ft_lstadd(&path, new);
		room = room->prev;
	}
	if (ft_lstsize(path) < 2)
		ft_lstdel(&path, NULL);
	return (path);
}
