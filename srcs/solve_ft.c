/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:36:28 by dthan             #+#    #+#             */
/*   Updated: 2019/11/27 14:55:15 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		place(t_block *block, int *ordinate, char **board)
{
	int	x;
	int	y;
	int	i;

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

void		clear_piece(char **board, int *ordinate)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (i < 8)
	{
		y = ordinate[i + 1];
		x = ordinate[i];
		board[y][x] = '.';
		i += 2;
	}
}

int			backtrack(t_block *blocks, char **board, int size)
{
	int	row;
	int	col;
	int	*temp_ordinate;

	row = -1;
	temp_ordinate = (int *)malloc(sizeof(int) * 8);
	if (!blocks)
		return (free_ordinate(temp_ordinate, TRUE));
	while (++row < size)
	{
		col = -1;
		while (++col < size)
		{
			copy_ordinate(temp_ordinate, blocks->ordinate);
			shift_ordinate(temp_ordinate, col, row);
			if (not_collision(board, size, temp_ordinate))
			{
				place(blocks, temp_ordinate, board);
				if (backtrack(blocks->next, board, size))
					return (free_ordinate(temp_ordinate, TRUE));
				clear_piece(board, temp_ordinate);
			}
		}
	}
	return (free_ordinate(temp_ordinate, FALSE));
}

void		solve(t_block *blocks)
{
	int		size;
	char	**board;

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
