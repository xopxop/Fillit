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

void	free_board(char **board, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		ft_strdel(&board[i]);
		i++;
	}
	free(board);
}

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

int		*copy_ordinate(int *src)
{
	int i;
	int *dst;

	i = 0;
	dst = (int*)malloc(sizeof(int) * 8);
	while (i < 8)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int		backtrack(t_block *blocks, char **board, int size)
{
	int row;
	int col;
	int *temp_ordinate;

	row = 0;
	if(!blocks)
		return (TRUE);
	while (row < size)
	{
		col = 0;
		while(col < size)
		{
			temp_ordinate = copy_ordinate(blocks->ordinate);
			shift_ordinate(temp_ordinate, col, row);
			if (collision(board, blocks, size, temp_ordinate))
			{
				place(blocks, temp_ordinate, board);
				if (backtrack(blocks->next, board, size))
					return (TRUE);
				return (FALSE);
			}
			col++;
		}
		row++;
	}
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
}
