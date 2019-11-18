/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:36:39 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/19 00:10:07 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/get_next_line.h"

typedef	struct		s_block
{
	char		**tetro;
	char		chr;
	struct s_block	*next;
}			t_block;

int	store_blocks(t_block **first, char *file);
int	check_block(char **tetro);
int	check_valid(char **tetro);
int	count_adjacent(char **tetro, int i, int j);
void	add_block(t_block **first, char **block);
int	check_newline(int fd);
void	ft_shifting(char **tetro);
int	amount_x(char **tetro);
int	amount_y(char **tetro);
void	shift_tetro(char **tetro);
void	print_blocks(t_block *first);

#endif
