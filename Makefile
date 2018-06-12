# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffloris <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/13 09:39:19 by ffloris           #+#    #+#              #
#    Updated: 2018/05/03 10:16:27 by ffloris          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

GCC_FLAGS = -Werror -Wextra -Wall

OBJS_DIR = objs
SRCS_DIR = srcs
SRCS_INCLUDES_DIR = includes/

LIBFT_DIR = libft
LIBFT_FILE = $(LIBFT_DIR)/libft.a
LIBFT_INCLUDES_DIR = $(LIBFT_DIR)/includes/
INCLUDE_DIRS = -I$(SRCS_INCLUDES_DIR) -I$(LIBFT_INCLUDES_DIR)

FILES = main free_line free_room free_farm is_comment skip_comments \
		skip_commands get_command parse_input parse_ants \
		parse_room parse_room_info find_room_info get_room_by_name \
		parse_rooms is_link parse_link parse_links parse_farm set_turns \
		set_turn move_ant get_shortest_path run_dijkstra get_table_size \
		print_result print_error

OBJS_WITH_DIR = $(patsubst %, $(OBJS_DIR)/%.o, $(FILES))
SRCS = $(addsuffix .c, $(FILES))

GREEN_COLOR = "\033[0;32m"
DEFAULT_COLOR = "\033[0m"

all: comp_libft $(NAME)

norm:
	@make -C $(LIBFT_DIR)/ norm
	@norminette $(SRCS_INCLUDES_DIR) $(SRCS_DIR)

comp_libft:
	@make -C $(LIBFT_DIR)/

$(NAME): $(LIBFT_FILE) $(OBJS_DIR) $(OBJS_WITH_DIR)
	@echo "Lem_in:" $(GREEN_COLOR) $(NAME) $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) $(OBJS_WITH_DIR) -o $(NAME) $(LIBFT_FILE) $(INCLUDE_DIRS)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@echo "Lem_in:" $(GREEN_COLOR) $< $(DEFAULT_COLOR)
	@gcc $(GCC_FLAGS) -c $< -o $@ $(INCLUDE_DIRS)

clean:
	@make -C $(LIBFT_DIR)/ clean
	@rm -rf $(OBJS_DIR) $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)

fclean:
	@make -C $(LIBFT_DIR)/ fclean
	@rm -rf $(OBJS_DIR) $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@rm -rf $(NAME)

re: fclean all

.PHONY: all norm comp_libft clean fclean re
