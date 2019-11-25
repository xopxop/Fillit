/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 18:26:17 by dthan             #+#    #+#             */
/*   Updated: 2019/11/22 18:26:20 by dthan            ###   ########.fr       */
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

void    free_blocks(t_block *blocks)
{
    t_block *temp_block;
    int *temp_ordinate;

    temp_block = NULL;
    temp_ordinate = NULL;
    while(blocks)
    {
        temp_block = blocks;
        temp_ordinate = blocks->ordinate;
        blocks = blocks->next;
        free(temp_ordinate);
        free(temp_block);
    }
}
