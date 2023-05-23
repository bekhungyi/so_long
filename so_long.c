/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/23 18:44:24 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_vars	vars;

	if (ac == 2 && check_file(ac, av, &vars))
	{
		render (&vars);
		mlx_loop(vars.mlx);
	}
	else
		ft_printf("Error.\nMap is invalid or not found.");
	return (0);
}
