/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_command(t_list *input)
{
	char	*str;

	if (!input)
		return (-1);
	str = (char*)(input->content);
	if (!str || ft_strlen(str) <= 2)
		return (-1);
	if (str[0] != COMMENT_ID || str[1] != COMMENT_ID)
		return (-1);
	if (!ft_strcmp(str + 2, START_COMMAND_ID))
		return (START_COMMAND);
	if (!ft_strcmp(str + 2, END_COMMAND_ID))
		return (END_COMMAND);
	return (0);
}
