/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/10 00:49:34 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "mlx/mlx.h"

int	main(void)
{
	void	*mlx;
    void    *win;

	mlx = mlx_init();
    win = mlx_new_window(mlx, 200, 200, "bingbong");
    mlx_loop(mlx);
}
