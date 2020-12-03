/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 04:36:20 by dthan             #+#    #+#             */
/*   Updated: 2019/11/27 14:28:52 by sadawi           ###   ########.fr       */
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

int		box_collide(int *ordinate, int size)
{
	int i;

	i = 0;
	while (i < 8)
	{
		if (ordinate[i] >= size || ordinate[i] > size)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		not_collision(char **board, int size, int *ordinate)
{
	return ((box_collide(ordinate, size)) && (piece_collide(ordinate, board)));
}
