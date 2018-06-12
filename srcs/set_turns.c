/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_turns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		set_turns(t_farm *farm)
{
	int		ants_arrived;
	t_list	*path;

	if (!(path = get_shortest_path(farm)))
		return (0);
	ants_arrived = 0;
	while (ants_arrived < farm->n_ants)
	{
		if (!set_turn(farm, path, &ants_arrived))
			break ;
	}
	ft_lstdel(&path, NULL);
	return (ants_arrived == farm->n_ants);
}
