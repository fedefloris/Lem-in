/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		set_link_rooms(t_list *input, t_farm *farm,
							t_room **from, t_room **to)
{
	char	**link;

	if (!(link = ft_strsplit((char*)(input->content), '-')))
		return (0);
	if (!(*from = get_room_by_name(farm->rooms, link[0])) ||
		!(*to = get_room_by_name(farm->rooms, link[1])) ||
		*from == *to)
	{
		ft_strdel_table(link);
		return (0);
	}
	ft_strdel_table(link);
	return (1);
}

static t_link	*get_link(t_room *from, t_room *to)
{
	t_link	*link;

	if (!(link = (t_link*)malloc(sizeof(t_link))))
		return (NULL);
	link->from = from;
	link->to = to;
	return (link);
}

int				parse_link(t_list *input, t_farm *farm)
{
	t_list	*new;
	t_link	*link;
	t_room	*from;
	t_room	*to;

	if (!set_link_rooms(input, farm, &from, &to) ||
		!(link = get_link(from, to)))
		return (0);
	if (!(new = ft_lstcpy(link, sizeof(t_link))))
	{
		free(link);
		return (0);
	}
	ft_lstappend(&(farm->links), new);
	return (1);
}
