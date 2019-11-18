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

void	print_blocks(t_block *first) // tmp function to print blocks for debugging
{
	int i;

	while (first)
	{
		i = 0;
		while (i < 4)
			ft_putendl(first->tetro[i++]);
		first = first->next;
		if (first)
			ft_putchar('\n');
	}
}
