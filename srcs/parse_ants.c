/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		parse_n_ants(t_list **input, t_farm *farm)
{
	char	*str;

	while (*input)
	{
		if (skip_comments(input) || skip_commands(input))
			continue ;
		break ;
	}
	if (!(*input))
		return (0);
	str = (char*)((*input)->content);
	farm->n_ants = (int)ft_atoi(str);
	if (!ft_isinteger(str) || farm->n_ants <= 0)
		return (0);
	*input = (*input)->next;
	return (*input != NULL);
}

static t_list	*get_ant(int id)
{
	t_list	*new;
	t_ant	*ant;

	if (!(ant = (t_ant*)malloc(sizeof(t_ant))))
		return (NULL);
	ant->id = id;
	ant->room = NULL;
	if (!(new = ft_lstcpy(ant, sizeof(t_ant))))
		free(ant);
	return (new);
}

int				parse_ants(t_list **input, t_farm *farm)
{
	t_list	*new;
	int		i;

	if (!parse_n_ants(input, farm))
		return (0);
	i = 0;
	while (++i <= farm->n_ants)
	{
		if (!(new = get_ant(i)))
		{
			ft_lstdel(&(farm->ants), ft_struct_del);
			return (0);
		}
		ft_lstappend(&(farm->ants), new);
	}
	return (1);
}
