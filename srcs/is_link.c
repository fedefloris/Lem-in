/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_link.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_link(t_list *input)
{
	size_t	link_size;
	char	**link;

	if (!input)
		return (0);
	if (!(link = ft_strsplit((char*)(input->content), '-')))
		return (0);
	link_size = get_table_size(link);
	ft_strdel_table(link);
	if (link_size < 2)
		return (0);
	return (1);
}
