/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 14:33:22 by sadawi            #+#    #+#             */
/*   Updated: 2019/12/02 13:01:55 by dthan            ###   ########.fr       */
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
			ft_putstr("error\n");
		else if (!check_amount(blocks))
			ft_putstr("error\n");
		else
		{
			solve(blocks);
			free_blocks(blocks);
		}
	}
	return (0);
}
