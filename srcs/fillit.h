/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:36:39 by sadawi            #+#    #+#             */
/*   Updated: 2019/11/27 17:20:14 by sadawi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define TRUE 1
# define FALSE 0
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/get_next_line.h"

typedef	struct		s_block
{
	char			**tetro;
	char			chr;
	int				*ordinate;
	int				height;
	int				length;
	struct s_block	*next;
}					t_block;

/*
** BOARD_FT
*/

char				*gen_line(int size);
char				**gen_board(int size);
int					count_tetromines(t_block *blocks);
int					board_starting_size(int tetromines_nbr);
char				**get_board(t_block *blocks);

/*
** CHECK_FT
*/

int					check_newline(int fd);
int					check_input(char **lines_read);
int					check_valid_char(char **lines_read);
int					count_adjacent(char **lines_read, int row, int col);
int					check_amount(t_block *blocks);

/*
** COlLISION FT
*/

int					piece_collide(int *ordinate, char **board);
int					box_collide(int *ordinate, int size);
int					not_collision(char **board, int size, int *ordinate);

/*
** DISPLAY_FT
*/

void				print_board(char **board);

/*
** GET_INFO_FT
*/

int					*get_xy(char **shifted_line_read);
int					get_height(int *block_ordinate);
int					get_length(int *block_ordinate);

/*
** SHIFTING_FT
*/

int					amount_x(char **tetro);
int					amount_y(char **tetro);
void				shift_tetro(char **tetro);

/*
** SOLVE_FT
*/

void				place(t_block *block, int *ordinate, char **board);
int					backtrack(t_block *blocks, char **board, int size);
void				solve(t_block *blocks);

/*
** STORE_BLOCK_FT
*/

int					store_blocks(t_block **block, char *file);
void				add_block(t_block **block, char **lines_read);
void				change_char(t_block *new);
void				add_info_into_block(t_block *block, char **lines_read, \
char chr);
int					check_helper(t_block **block, char **lines_read);

/*
**ORDINATION_FT
*/

void				shift_ordinate(int *ordinate, int x, int y);
void				copy_ordinate(int *dst, int *src);

/*
** FREE_FT
*/

void				free_board(char **board, int size);
void				free_blocks(t_block *blocks);
int					free_ordinate(int *ordinate, int bool);

#endif
