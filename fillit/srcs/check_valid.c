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

int	check_block(char **tetro)
{
	int i;
	int j;
	int adj;

	if (!check_valid(tetro))
		return (0);
	i = 0;
	adj = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			if (tetro[i][j++] == '#')
				adj += count_adjacent(tetro, i, j - 1);
		i++;
	}
	shift_tetro(tetro);
	return ((adj >= 6));
}
/*
** check_valid checks if the tetrimino only contains '.' and '#', and that
** there is precisely 4 '#' characters.
*/
int	check_valid(char **tetro)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetro[i][j] == '#')
				count++;
			else if (tetro[i][j] != '.')
				return (0);
			j++;
		}
		i++;
	}
	return ((count == 4));
}

/*
** count_adjacent counts how many adjacent '#' characters each '#' character has.
*/

int	count_adjacent(char **tetro, int i, int j)
{
	int count;

	count = 0;
	if ((i - 1) >= 0)
		if (tetro[i - 1][j] == '#')
			count++;
	if ((i + 1) <= 3)
		if (tetro[i + 1][j] == '#')
			count++;
	if ((j - 1) >= 0)
		if (tetro[i][j - 1] == '#')
			count++;
	if ((j + 1) <= 3)
		if (tetro[i][j + 1] == '#')
			count++;
	return (count);
}
