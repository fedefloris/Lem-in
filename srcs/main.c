/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(void)
{
	t_list	*input;
	t_farm	farm;

	if (parse_farm(&input, &farm) && set_turns(&farm))
		print_result(input, farm.turns);
	else
		print_error();
	ft_lstdel(&input, free_line);
	free_farm(&farm);
	return (0);
}
