/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_farm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_farm(t_farm *farm)
{
	ft_lstdel(&(farm->ants), ft_struct_del);
	ft_lstdel(&(farm->rooms), free_room);
	ft_lstdel(&(farm->turns), ft_struct_del);
	ft_lstdel(&(farm->links), ft_struct_del);
}
