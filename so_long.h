/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:17:57 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/17 19:25:47 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

#include "mlx/mlx.h"
#include "./lib/libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		map_height;
	int		map_length;
}				t_vars;


int check_filetype(char *str);

int check_map(int ac, char **av, t_vars vars);



# define COLOR_RED		0xFF0000
# define COLOR_YELLOW	0xFFFF00
# define COLOR_BLACK	0x000000


# endif