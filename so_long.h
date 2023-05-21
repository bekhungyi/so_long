/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:17:57 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/21 19:02:55 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

#include "mlx/mlx.h"
#include "./libft/libft.h"
#include <unistd.h>
#include <fcntl.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		map_height;
	int		map_length;
	char	**map;
	int		rows;
}				t_vars;


int check_filetype(char *str);

int check_file(int ac, char **av, t_vars *vars);

int check_map(t_vars *vars);

int check_valid_path(t_vars *vars);

# define COLOR_RED		0xFF0000
# define COLOR_YELLOW	0xFFFF00
# define COLOR_BLACK	0x000000


# endif