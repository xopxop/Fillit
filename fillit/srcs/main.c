/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:04:40 by dthan             #+#    #+#             */
/*   Updated: 2019/11/19 00:12:45 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_block *blocks;

	blocks = NULL;
	if (argc != 2)
		ft_putstr("./fillit [input_file]\n");
	else
	{
		if (!store_blocks(&blocks, argv[1]))
			ft_putstr("error");
		else
		{
			print_blocks(blocks);
			board(blocks);
		}
	}
	return (0);
}
