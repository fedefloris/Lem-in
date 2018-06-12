/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:50:19 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/27 18:20:01 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	parse_line(t_list **input, char *line)
{
	size_t	line_size;
	t_list	*new;

	if (!(line_size = ft_strlen(line)))
		return (0);
	if (!(new = ft_lstnew(line, line_size + 1)))
	{
		free(line);
		return (0);
	}
	ft_lstappend(input, new);
	free(line);
	return (1);
}

int			parse_input(t_list **input)
{
	char	*line;
	int		res;

	*input = NULL;
	line = NULL;
	while ((res = get_next(0, &line, '\n')) > 0)
	{
		if (!parse_line(input, line))
			return (0);
	}
	if (line && !parse_line(input, line))
		return (0);
	return (*input != NULL);
}
