/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:31:15 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/27 14:31:18 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Print board which has been filled in
*/

void	print_board(char **board)
{
	int i;

	i = 0;
	while (board[i])
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}
