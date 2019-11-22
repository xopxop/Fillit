/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 00:14:03 by dthan             #+#    #+#             */
/*   Updated: 2019/11/21 00:42:43 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place(t_block *block, int *ordinate, char **board)
{
	int x;
	int y;
	int i;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		y = ordinate[i + 1];
		x = ordinate[i];
		board[y][x] = block->chr;
		i += 2;
	}
}

void	clear_piece(char **grid, int *tab)
{
	int i;
	int x;
	int y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = tab[i + 1];
		x = tab[i];
		grid[y][x] = '.';
		i += 2;
	}
}

int		backtrack(t_block *blocks, char **board, int size)
{
	int row;
	int col;
	int *temp_ordinate;

	row = 0;
	temp_ordinate = (int *)malloc(sizeof(int) * 8);
	if(!blocks)
	{
		free(temp_ordinate);
		return (TRUE);
	}
	while (row < size)
	{
		col = 0;
		while(col < size)
		{
			copy_ordinate(temp_ordinate, blocks->ordinate);
			shift_ordinate(temp_ordinate, col, row);
			if (not_collision(board, size, temp_ordinate))
			{
				place(blocks, temp_ordinate, board);
				if (backtrack(blocks->next, board, size))
				{
					free(temp_ordinate);
					return (TRUE);
				}
				clear_piece(board, temp_ordinate);
				free(temp_ordinate);
				return (FALSE);
			}
			col++;
		}
		row++;
	}
	free(temp_ordinate);
	return (FALSE);
}

void	solve(t_block *blocks)
{
	int size;
	char **board;

	size = board_starting_size(count_tetromines(blocks));
	board = get_board(blocks);
	while (!backtrack(blocks, board, size))
	{
		free_board(board, size);
		size += 1;
		board = gen_board(size);
	}
	print_board(board);
	free_board(board, size);
}
