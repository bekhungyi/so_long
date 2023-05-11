/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:17:57 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/11 18:09:44 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
    int     x;
    int     y;
    int     dx;
    int     dy;
}				t_vars;

typedef struct	s_color {
	int     red;
    int     yellow;
}				t_color;

# define COLOR_RED		0xFF0000
# define COLOR_YELLOW	0xFFFF00

# endif