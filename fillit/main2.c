//ADD HEADER

#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/get_next_line.h"

/*
** Store_blocks stores each tetrimino in a linked list
** FALSE when can't open the file, can't locate malloc, get_next_line false
** While using check_block to check each tetrimino.
** currently unfinished, only finds the first tetrimino from a file.
*/

int	store_blocks(t_block **first, char *file)
{
	int file_descriptor;
	char **buf;
	char *tmp;
	int i;

	i = 0;

	if (!(file_descriptor = open(file, O_RDONLY)))
		return (FALSE);
	if (!(buf = (char**)malloc(sizeof(*buf) * 4)))
		return (FALSE);
	while (i < 4)
		if (get_next_line(file_descriptor, &buf[i]) > 1 || ft_strlen(buf[i++]) != 4)
			return (FALSE);
	return (check_block(buf));
}

/*
** check_block uses both check_valid and count_adjacent to fully determine if the tetrimino is valid.
*/

int	check_block(char **tetro)
{
	int row;
	int col;
	int adjacent;

	row = 0;
	adjacent = 0;
	if (!check_valid_char(tetro))
		return (FALSE);
	while (row < 4)
	{
		col = 0;
		while (col < 4)
			if (tetro[row][col++] == '#')
				adjacent += count_adjacent(tetro, row, col - 1);
		row++;
	}
	return (adjacent >= 6 ? TRUE : FALSE);
}
/*
  check_valid checks if the tetrimino only contains '.' and '#', and that there is precisely 4 '#' characters.
*/
int	check_valid_char(char **tetro)
{
	int row;
	int col;
	int count;

	row = 0;
	count = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (tetro[row][col] == '#')
				count++;
			else if (tetro[row][col] != '.')
				return (0);
			col++;
		}
		row++;
	}
	return (count == 4 ? TRUE : FALSE);
}

/*
** count_adjacent counts how many adjacent '#' characters each '#' character has.
*/

int	count_adjacent(char **tetro, int row, int col)
{
	int count;

	count = 0;
	if ((row - 1) >= 0)
		if (tetro[row - 1][col] == '#')
			count++;
	if ((row + 1) <= 3)
		if (tetro[row + 1][col] == '#')
			count++;
	if ((col - 1) >= 0)
		if (tetro[row][col - 1] == '#')
			count++;
	if ((col + 1) <= 3)
		if (tetro[row][col + 1] == '#')
			count++;
	return (count);
}

/*
  add_block adds the block to the end of a linked list.
*/

void	add_block(t_block **first, char **block)
{
	t_block *tmp;
	t_block *new;
	char c;

	c = 'A';
	tmp = *first;
	while (tmp->next)
	{
		tmp = tmp->next;
		c++;
	}
	new = (t_block*)malloc(sizeof(t_block));
	new->tet_id = block;
	new->character = c;
	tmp->next = new;
}

int		main(int argc, char **argv)
{
  t_block *blocks;

  if (argc != 2)
    ft_putstr("./fillit [input_file]\n");
  else
    {
      if (!store_blocks(&blocks, argv[1]))
	ft_putstr("error");
      else
      {
	ft_putstr("tetromino is valid");
	printf("%s\n", t_block->*tet_id);
      }
    }
  return (0);
}
