/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 15:16:50 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/21 15:48:28 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
    t_vars  vars;
    
    if (check_map(ac, av, &vars))
    {
        ft_printf("Game is rendered.");
    }
    else
        ft_printf("Error: Map is invalid or not found.");
    return 0;
}
