/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:14:58 by dthan             #+#    #+#             */
/*   Updated: 2019/11/19 00:23:18 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** check_newline checks if there is a line which only contains the newline
** character '\n' between blocks.
** Returns 1 when file has been read completely.
** If anything else is found, returns 0 which indicates an error.
*/

int	check_newline(int fd)
{
	char *tmp;

	if (!get_next_line(fd, &tmp))
		return (1);
	else if (!ft_strequ(tmp, ""))
	{
		free(tmp);
		return (0);
	}
	return (-1);
}

/*
** check_block uses both check_valid and count_adjacent to fully determine if
** the tetrimino is valid.
*/

int	check_input(char **lines_read)
{
	int row;
	int col;
	int adj;

	if (!check_valid_char(lines_read))
		return (FALSE);
	row = 0;
	adj = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
			if (lines_read[row][col++] == '#')
				adj += count_adjacent(lines_read, row, col - 1);
		row++;
	}
	shift_tetro(lines_read);
	return ((adj >= 6));
}
/*
** check_valid checks if the tetrimino only contains '.' and '#', and that
** there is precisely 4 '#' characters.
*/
int	check_valid_char(char **lines_read)
{
	int row;
	int col;
	int count;

	row = 0;
	count = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (lines_read[row][col] == '#')
				count++;
			else if (lines_read[row][col] != '.')
				return (FALSE);
			col++;
		}
		row++;
	}
	return ((count == 4));
}

/*
** count_adjacent counts how many adjacent '#' characters each '#' character has.
*/

int	count_adjacent(char **lines_read, int row, int col)
{
	int count;

	count = 0;
	if ((row - 1) >= 0)
		if (lines_read[row - 1][col] == '#')
			count++;
	if ((row + 1) <= 3)
		if (lines_read[row + 1][col] == '#')
			count++;
	if ((col - 1) >= 0)
		if (lines_read[row][col - 1] == '#')
			count++;
	if ((col + 1) <= 3)
		if (lines_read[row][col + 1] == '#')
			count++;
	return (count);
}
