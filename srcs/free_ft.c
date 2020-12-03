/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:29:45 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/27 14:51:53 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_board(char **board, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&board[i]);
		i++;
	}
	free(board);
}

void	free_blocks(t_block *blocks)
{
	t_block *temp_block;
	int		*temp_ordinate;

	temp_block = NULL;
	temp_ordinate = NULL;
	while (blocks)
	{
		temp_block = blocks;
		temp_ordinate = blocks->ordinate;
		blocks = blocks->next;
		free(temp_ordinate);
		free(temp_block);
	}
}

int		free_ordinate(int *ordinate, int bool)
{
	free(ordinate);
	return (bool);
}
