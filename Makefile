# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/09 22:30:52 by bhung-yi          #+#    #+#              #
#    Updated: 2023/05/21 18:55:53 by bhung-yi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
FLAGS		= -Wall -Werror -Wextra
RM			= /bin/rm -f

LIBFTPATH	= ./libft
LIBFTNAME	= libft.a

MLX_DIR		= mlx
MLX_FLAGS	= 	-L$(MLX_DIR) -lmlx \
				-framework OpenGL \
				-framework AppKit

UTILS		= 	./utils/check_file.c \
				./utils/check_map.c \
				./utils/check_path.c

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

all: $(NAME)

$(NAME):
	make -C $(LIBFTPATH)
	mv $(LIBFTPATH)/$(LIBFTNAME) $(LIBFTNAME)
	$(CC) $(CFLAGS) so_long.c $(LIBFTNAME) $(UTILS) $(MLX_FLAGS) -o $(NAME)

re: fclean all

clean:
	$(RM) -r *.o
	$(RM) -r $(LIBFTPATH)/*.o

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFTNAME)
