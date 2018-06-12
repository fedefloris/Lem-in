/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_farm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	setup_farm(t_farm *farm)
{
	farm->ants = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->rooms = NULL;
	farm->turns = NULL;
	farm->links = NULL;
}

int			parse_farm(t_list **input, t_farm *farm)
{
	t_list	*in;

	setup_farm(farm);
	if (!parse_input(input))
		return (0);
	in = *input;
	if (!parse_ants(&in, farm))
		return (0);
	if (!parse_rooms(&in, farm))
		return (0);
	if (!parse_links(&in, farm))
		return (0);
	return (1);
}
