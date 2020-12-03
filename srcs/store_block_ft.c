/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_block_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:25:15 by dthan             #+#    #+#             */
/*   Updated: 2019/11/27 15:33:31 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** store_blocks ft: check open file, and read input from the fd
** then check if the input is valid, if yes add input into linked list
*/

int		check_helper(t_block **block, char **lines_read)
{
	if (check_input(lines_read))
	{
		add_block(block, lines_read);
		free_board(lines_read, 4);
		return (TRUE);
	}
	else
	{
		free_board(lines_read, 4);
		return (FALSE);
	}
}

int		store_blocks(t_block **block, char *file)
{
	int		fd;
	char	**lines_read;
	int		line_num;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (FALSE);
	while (1)
	{
		if (!(lines_read = (char**)malloc(sizeof(*lines_read) * 4)))
			return (FALSE);
		line_num = 0;
		while (line_num < 4)
			if (get_next_line(fd, &lines_read[line_num]) < 1 ||\
					ft_strlen(lines_read[line_num++]) != 4)
			{
				free_board(lines_read, line_num);
				return (FALSE);
			}
		if (!check_helper(block, lines_read))
			return (FALSE);
		if ((line_num = check_newline(fd)) != -1)
			return (line_num);
	}
	close(fd);
	return (FALSE);
}

void	add_info_into_block(t_block *block, char **lines_read, char chr)
{
	block->tetro = lines_read;
	block->ordinate = get_xy(lines_read);
	block->chr = chr;
	change_char(block);
	block->height = get_height(block->ordinate);
	block->length = get_length(block->ordinate);
	block->next = NULL;
}

void	add_block(t_block **block, char **lines_read)
{
	t_block		*temp;
	t_block		*new;
	char		character;

	character = 'A';
	temp = *block;
	if (*block)
	{
		character = 'B';
		while (temp->next)
		{
			temp = temp->next;
			character++;
		}
	}
	new = (t_block*)malloc(sizeof(t_block));
	add_info_into_block(new, lines_read, character);
	if (!*block)
		*block = new;
	else
		temp->next = new;
}

void	change_char(t_block *new)
{
	int row;
	int col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
			if (new->tetro[row][col++] == '#')
				new->tetro[row][col - 1] = new->chr;
		row++;
	}
}
