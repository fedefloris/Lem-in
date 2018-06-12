/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_str(t_list *el)
{
	ft_putstr((char*)(el->content));
	if (((char*)(el->content))[0] != '\n')
		ft_putchar('\n');
}

static void	print_turn(t_list *el)
{
	t_turn	*turn;

	turn = (t_turn*)(el->content);
	ft_printf("L%d-%s", turn->ant->id, turn->room->name);
	if (turn->last_move)
		ft_putchar('\n');
	else
		ft_putchar(' ');
}

void		print_result(t_list *input, t_list *turns)
{
	ft_lstiter(input, print_str);
	ft_putchar('\n');
	ft_lstiter(turns, print_turn);
}
