# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 22:30:52 by bhung-yi          #+#    #+#              #
#    Updated: 2023/05/10 01:24:20 by bhung-yi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= /bin/rm -f

MLX_DIR		= mlx
MLX_FLAGS	= 	-L$(MLX_DIR) -lmlx \
				-framework OpenGL \
				-framework AppKit

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) so_long.c $(MLX_FLAGS) -o $(NAME)

re: fclean all

clean:
	$(RM) -r *.o

fclean: clean
	$(RM) $(NAME)
