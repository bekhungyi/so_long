/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhung-yi <bhung-yi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:36:47 by bhung-yi          #+#    #+#             */
/*   Updated: 2023/05/17 19:56:22 by bhung-yi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int			l1;
// 	int			l2;
// 	char		*str;

// 	if (s1 == NULL || s2 == NULL)
// 		return (NULL);
// 	l1 = ft_strlen(s1);
// 	l2 = ft_strlen(s2);
// 	str = malloc((l1 + l2 + 1) * sizeof(char));
// 	if (str == NULL)
// 		return (NULL);
// 	ft_strlcpy (str, s1, l1 + l2 + 1);
// 	ft_strlcat (str, s2, l1 + l2 + 1);
// 	return (str);
// }

char	*ft_strjoin(char *save, char *buf, int r)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_strlen(save) + r + 1));
	if (!res)
		return (NULL);
	if (save)
	{
		while (save[i])
		{
			res[i] = save[i];
			i++;
		}
		free(save);
	}
	while (j < r)
		res[i++] = buf[j++];
	res[i] = '\0';
	return (res);
}
