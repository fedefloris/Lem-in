/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffloris <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 16:51:41 by ffloris           #+#    #+#             */
/*   Updated: 2018/04/30 16:14:21 by ffloris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libft.h"
# define COMMENT_ID '#'
# define ERROR_MESSAGE "ERROR"
# define START_COMMAND_ID "start"
# define END_COMMAND_ID "end"
# define START_COMMAND 1
# define END_COMMAND 2

typedef struct		s_room
{
	int				x;
	int				y;
	char			*name;
	int				dist;
	int				available;
	struct s_room	*prev;
}					t_room;
typedef struct		s_link
{
	t_room			*from;
	t_room			*to;
}					t_link;
typedef struct		s_ant
{
	int				id;
	t_room			*room;
}					t_ant;
typedef struct		s_turn
{
	t_ant			*ant;
	t_room			*room;
	int				last_move;
}					t_turn;
typedef struct		s_farm
{
	int				n_ants;
	t_list			*ants;
	t_list			*rooms;
	t_room			*start;
	t_room			*end;
	t_list			*turns;
	t_list			*links;
}					t_farm;
size_t				get_table_size(char **table);
void				free_line(void *content, size_t content_size);
void				free_room(void *content, size_t content_size);
void				free_farm(t_farm *farm);
int					is_comment(t_list *input);
int					skip_comments(t_list **input);
int					skip_commands(t_list **input);
int					get_command(t_list *input);
int					is_link(t_list *input);
int					parse_input(t_list **input);
int					parse_ants(t_list **input, t_farm *farm);
int					parse_rooms(t_list **input, t_farm *farm);
int					parse_room(t_list **input, t_farm *farm);
t_room				*parse_room_info(char *str);
int					find_room_info(t_farm *farm, t_room *room);
t_room				*get_room_by_name(t_list *rooms, char *name);
int					parse_links(t_list **input, t_farm *farm);
int					parse_link(t_list *input, t_farm *farm);
int					parse_farm(t_list **input, t_farm *farm);
int					move_ant(t_ant *ant, t_farm *farm, t_list *path);
int					set_turns(t_farm *farm);
int					set_turn(t_farm *farm, t_list *path,
												int *ants_arrived);
int					run_dijkstra(t_farm *farm);
t_list				*get_shortest_path(t_farm *farm);
void				print_result(t_list *input, t_list *turns);
void				print_error(void);
#endif
