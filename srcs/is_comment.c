/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_comment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_comment(t_list *input)
{
	char	*str;

	if (!input)
		return (0);
	str = (char*)(input->content);
	if (!str || ft_strlen(str) <= 1)
		return (0);
	if (str[0] != COMMENT_ID || str[1] == COMMENT_ID)
		return (0);
	return (1);
}
