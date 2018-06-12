/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_table_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

size_t		get_table_size(char **table)
{
	size_t size;

	size = 0;
	if (table)
		while (table[size])
			size++;
	return (size);
}
