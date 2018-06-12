/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_turn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*get_turn(t_ant *ant, t_room *room)
{
	t_list	*new;
	t_turn	*turn;

	if (!(turn = (t_turn*)malloc(sizeof(t_turn))))
		return (NULL);
	turn->ant = ant;
	turn->room = room;
	turn->last_move = 0;
	if (!(new = ft_lstcpy(turn, sizeof(t_turn))))
		free(turn);
	return (new);
}

int				set_turn(t_farm *farm, t_list *path,
					int *ants_arrived)
{
	t_list	*ants;
	t_list	*new;
	t_ant	*ant;

	ants = farm->ants;
	while (ants)
	{
		ant = (t_ant*)(ants->content);
		if (move_ant(ant, farm, path))
		{
			if (!(new = get_turn(ant, ant->room)))
				return (0);
			ft_lstappend(&(farm->turns), new);
			if (ant->room == farm->end)
				(*ants_arrived)++;
		}
		ants = ants->next;
	}
	((t_turn*)(new->content))->last_move = 1;
	return (1);
}
