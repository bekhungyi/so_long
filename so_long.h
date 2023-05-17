/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:17:57 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/15 17:13:29 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "mlx/mlx.h"
#include "./lib/libft/libft.h"
#include <unistd.h>
#include <stdio.h>

int check_filetype(char *str);

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

    void	*mlx;
	void	*win;
    void    *imgNew;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    t_data  img;
    int     x;
    int     y;
}				t_vars;

typedef struct	s_color {
	int     red;
    int     yellow;
}				t_color;

# define COLOR_RED		0xFF0000
# define COLOR_YELLOW	0xFFFF00
# define COLOR_BLACK	0x000000


# endif