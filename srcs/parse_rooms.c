/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		parse_rooms(t_list **input, t_farm *farm)
{
	while (*input)
	{
		if (skip_comments(input) || skip_commands(input))
			continue ;
		if (!parse_room(input, farm))
			return (0);
		if (is_link(*input))
			break ;
		*input = (*input)->next;
	}
	if (farm->start == NULL || farm->end == NULL)
		return (0);
	return (*input != NULL);
}
