/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:10:34 by dthan             #+#    #+#             */
/*   Updated: 2019/11/21 16:10:59 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*get_xy(char **shifted_line_read)
{
	int *block_ordinate;
	int x;
	int y;
	int i;

	i = 0;
	y = 0;
	block_ordinate = (int*)malloc(sizeof(int) * 8);
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (shifted_line_read[y][x] != '.')
			{
				block_ordinate[i] = x;
				block_ordinate[i + 1] = y;
				i += 2;
			}
			x++;
		}
		y++;
	}
	return (block_ordinate);
}

int     get_height(int *block_ordinate)
{
    int i;
    int height;

    height = 0;
    i = 0;
	while (block_ordinate[i] < 8)
	{
		if (i % 2 == 1 && height <= block_ordinate[i])
			height = block_ordinate[i] + 1;
		i++;
	}
    return (height);
}

int     get_length(int *block_ordinate)
{
    int i;
    int length;

    length = 0;
    i = 0;
	while (block_ordinate[i] < 8)
	{
		if (i % 2 == 0 && length <= block_ordinate[i])
			length = block_ordinate[i] + 1;
		i++;
	}
    return (length);
}
