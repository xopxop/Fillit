/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:51:57 by dthan             #+#    #+#             */
/*   Updated: 2019/11/19 00:53:32 by dthan            ###   ########.fr       */
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
	while(board[i])
	{
		ft_putstr(board[i]);
		ft_putchar('\n');
		i++;
	}
}
