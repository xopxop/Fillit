/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:21:09 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/27 14:25:19 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Generate a line in 2D array, set vallue '?'
*/

char	*gen_line(int size)
{
	char	*line;
	int		i;

	i = 0;
	if (!(line = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size)
	{
		line[i] = '.';
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
** Generate a board, 2D array
*/

char	**gen_board(int size)
{
	char	**board;
	char	*line;
	int		i;

	i = 0;
	if (!(board = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (i < size)
	{
		board[i] = (char*)malloc(sizeof(char) * size + 1);
		line = gen_line(size);
		ft_strcpy(board[i], line);
		free(line);
		i++;
	}
	board[i] = NULL;
	return (board);
}

/*
** Count number of tetromines in the linked list
*/

int		count_tetromines(t_block *blocks)
{
	int tetromines_nbr;

	tetromines_nbr = 0;
	while (blocks != NULL)
	{
		tetromines_nbr++;
		blocks = blocks->next;
	}
	return (tetromines_nbr);
}

/*
** Finding the board starting size. NOTE: the ft_sqrt is not 100% percisely
*/

int		board_starting_size(int tetromines_nbr)
{
	int board_size;

	board_size = ft_sqrt(tetromines_nbr * 4);
	return (board_size);
}

/*
** The ft, take the linked list, count the node in the linked linst then
** generate the board based on the number of the note
*/

char	**get_board(t_block *blocks)
{
	int		board_size;
	char	**board;
	int		tetromines_nbr;

	tetromines_nbr = count_tetromines(blocks);
	board_size = board_starting_size(tetromines_nbr);
	board = gen_board(board_size);
	return (board);
}
