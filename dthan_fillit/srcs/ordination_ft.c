/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordination_ft.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:11:58 by dthan             #+#    #+#             */
/*   Updated: 2019/11/22 18:12:00 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	shift_ordinate(int *ordinate, int x, int y)
{
	int i;

	i = 0;
	while(i < 8)
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
