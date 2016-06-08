# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spetit <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/27 13:08:08 by spetit            #+#    #+#              #
#    Updated: 2016/05/27 13:08:18 by spetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit

CC		    = gcc

CC_FLAGS     = -Wall -Wextra -Werror

SRCS		= main.c\
			parsing.c\
			controls.c\
			ft_map_new.c\
			resolve.c\
			controls2.c\
			resolve_controls.c

SRCS_O		= $(SRCS:.c=.o)

I_LIBFT 	= -Ilibft

LIBFT 		= -Llibft $(I_LIBFT) -lft

all:	$(NAME)


$(NAME): $(SRCS_O)
			@make -C libft
			@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I . $(LIBFT)
			@echo "$(NAME) as been successfuly done :)"

%.o: %.c
	@$(CC) $(CC_FLAGS) -I$ . -o $@ -c $< $(I_LIBFT)

clean:
		@make clean -C libft
		@rm -f $(SRCS_O)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
