/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:53:01 by sadawi            #+#    #+#             */
/*   Updated: 2019/10/23 17:11:41 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrep(char *str, const char *search, const char *replace)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i + j] == search[j] || *search == 0)
		{
			if (!search[j + 1] || *search == 0)
			  return (ft_strcat(ft_strcat(ft_strsub(str, 0, i), replace), ft_strsub(str, i + j + 1, j)));
			j++;
		}
		i++;
		j = 0;
	}
	return (str);
}
