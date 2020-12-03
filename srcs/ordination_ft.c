/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordination_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:33:05 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/27 14:33:12 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_ordinate(int *ordinate, int x, int y)
{
	int i;

	i = 0;
	while (i < 8)
	{
		ordinate[i] = ordinate[i] + x;
		ordinate[i + 1] = ordinate[i + 1] + y;
		i += 2;
	}
}

void	copy_ordinate(int *dst, int *src)
{
	int i;

	i = 0;
	while (i < 8)
	{
		dst[i] = src[i];
		i++;
	}
}
