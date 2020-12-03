/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:26:59 by dthan             #+#    #+#             */
/*   Updated: 2019/11/27 14:39:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** amount_x finds how much a tetromino has to be shifted to the left
*/

int		amount_x(char **tetro)
{
	int row;
	int col;

	col = 0;
	while (col < 4)
	{
		row = 0;
		while (row < 4)
			if (tetro[row++][col] == '#')
				return (col);
		col++;
	}
	return (0);
}

/*
** amount_x finds how much a tetromino has to be shifted up
*/

int		amount_y(char **tetro)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
			if (tetro[row][col++] == '#')
				return (row);
		row++;
	}
	return (0);
}

/*
** shift_tetro shifts the tetromino on the x and y axis to the upper left corner
*/

void	shift_tetro(char **tetro)
{
	int row;
	int col;
	int xy[2];

	xy[0] = amount_x(tetro);
	xy[1] = amount_y(tetro);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if ((tetro)[row][col] == '#')
			{
				(tetro)[row][col] = '.';
				(tetro)[row - xy[1]][col - xy[0]] = '#';
			}
			col++;
		}
		row++;
	}
}
