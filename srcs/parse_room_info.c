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

static int	set_coordinates(char *str, t_room *room)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(str) - 1;
	while (size > 0 && !ft_isspace(str[size]))
	{
		size--;
		i++;
	}
	if (!ft_isspace(str[size]) || !size || !i)
		return (0);
	room->y = ft_atoi_n(str + size, i);
	i = 0;
	size--;
	while (size > 0 && !ft_isspace(str[size]))
	{
		size--;
		i++;
	}
	if (!ft_isspace(str[size]) || !size || !i)
		return (0);
	room->x = ft_atoi_n(str + size, i);
	return (1);
}

static int	set_name(char *str, t_room *room)
{
	size_t	size;
	size_t	spaces;

	size = ft_strlen(str) - 1;
	spaces = 0;
	while (size != 0)
	{
		if (ft_isspace(str[size]))
			spaces++;
		if (spaces == 2)
			break ;
		size--;
	}
	if (spaces != 2)
		return (0);
	if (!(room->name = ft_strnew(size)))
		return (0);
	ft_strncpy(room->name, str, size);
	return (1);
}

t_room		*parse_room_info(char *str)
{
	t_room	*room;

	if (!(room = (t_room*)malloc(sizeof(t_room))))
		return (NULL);
	if (!set_coordinates(str, room) || !set_name(str, room) ||
		!ft_strlen(room->name) || room->name[0] == 'L' ||
		room->name[0] == '#')
	{
		free(room);
		return (NULL);
	}
	room->dist = INT_MAX - 1;
	room->available = 1;
	room->prev = NULL;
	return (room);
}
