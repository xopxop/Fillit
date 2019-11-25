/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:24:23 by dthan             #+#    #+#             */
/*   Updated: 2019/11/20 11:31:46 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

/*
** store_blocks ft: check open file, and read input from the fd
** then check if the input is valid, if yes add input into linked list
*/

int	store_blocks(t_block **block, char *file)
{
	int fd;
	char **lines_read;
	int line_num;

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
		if (check_input(lines_read))
		{
			add_block(block, lines_read);
			free_board(lines_read, 4);
		}
		else
		{
			free_board(lines_read, 4);
			return (FALSE);
		}
		if ((line_num = check_newline(fd)) != -1)
			return (line_num);
	}
	close(fd);
	return (FALSE);
}

void	add_block(t_block **block, char **lines_read)
{
	t_block *temp;
	t_block *new;
	char character;

	character = 'A';
	temp = *block;
	if (*block)
	{
		character = 'B';
		while(temp->next)
		{
			temp = temp->next;
			if (character > 'Z')
				character -= 26;
			else
				character++;
		}
	}
	new = (t_block*)malloc(sizeof(t_block));
	new->tetro = lines_read;
	new->chr = character;
	change_char(new);
	new->ordinate = get_xy(lines_read);
	new->height = get_height(new->ordinate);
	new->length = get_length(new->ordinate);
	new->next = NULL;
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
