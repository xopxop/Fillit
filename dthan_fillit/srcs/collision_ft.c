/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 04:36:20 by dthan             #+#    #+#             */
/*   Updated: 2019/11/22 04:36:22 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		piece_collide(int *ordinate, char **board)
{
	int i;
	int size;

	i = 0;
	size = 4;
	while (size--)
	{
		if (board[ordinate[i + 1]][ordinate[i]] != '.')
			return (FALSE);
		i += 2;
	}
	return (TRUE);
}

int		box_collide(t_block *block, int size)
{
	if (block->height > size || block->length > size)
		return (FALSE);
	return (TRUE);
}

int 	collision(char **board, t_block *block, int size, int *ordinate)
{
	return ((box_collide(block, size)) && (piece_collide(ordinate, board)));
}
