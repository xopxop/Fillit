/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:36:39 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/18 02:14:29 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TRUE 1
# define FALSE 0

# include <stdio.h>

typedef struct		s_block
{
	char			**tet_id;
  	char			character;
	struct s_block	*next;
}					t_block;

int			store_blocks(t_block **first, char *file);

int			check_block(char **tetro);

int			check_valid_char(char **tetro);

int			count_adjacent(char **tetro, int i, int j);

void			add_block(t_block **first, char **block);

#endif
