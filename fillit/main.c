//ADD HEADER

#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/get_next_line.h"

/*
  store_blocks stores each tetrimino in a linked list, while using check_block to check each tetrimino.
  currently unfinished, only finds the first tetrimino from a file.
*/

int	store_blocks(t_block **first, char *file)
{
  int fd;
  char **buf;
  int i;
  
  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  while (1)
    {
      if (!(buf = (char**)malloc(sizeof(*buf) * 4)))
	return (0);
      i = 0;
      while (i < 4)
	  if (get_next_line(fd, &buf[i]) < 1 || ft_strlen(buf[i++]) != 4)
	    return (0);
      if (check_block(buf))
	  add_block(first, buf);
      else
	{
	  free(buf);
	  return (0);
	}
      if ((i = check_newline(fd)) != -1)
	return (i);
    }
  return (0);
}
/*
  check_newline checks if there is a line which only contains the newline character '\n' between blocks.
  Returns 1 when file has been read completely.
  If anything else is found, returns 0 which indicates an error.
*/
int	check_newline(int fd)
{
  char *tmp;
  
  if (!get_next_line(fd, &tmp))
    return (1);
  else if (!ft_strequ(tmp, ""))
    {
      free(tmp);
      return (0);
    }
  return (-1);
}

/*
  check_block uses both check_valid and count_adjacent to fully determine if the tetrimino is valid.
*/

int	check_block(char **tetro)
{
  int i;
  int j;
  int adj;

  if (!check_valid(tetro))
    return (0);
  i = 0;
  adj = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 4)
	if (tetro[i][j++] == '#')
	  adj += count_adjacent(tetro, i, j - 1);
      i++;
    }
  shift_tetro(tetro);
  return ((adj >= 6));
}
/*
  check_valid checks if the tetrimino only contains '.' and '#', and that there is precisely 4 '#' characters.
*/
int	check_valid(char **tetro)
{
  int i;
  int j;
  int count;

  i = 0;
  count = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 4)
	{
	  if (tetro[i][j] == '#')
	    count++;
	  else if (tetro[i][j] != '.')
	    return (0);
	  j++;
	}
      i++;
    }
  return ((count == 4));
}

/*
  count_adjacent counts how many adjacent '#' characters each '#' character has.
*/

int count_adjacent(char **tetro, int i, int j)
{
  int count;

  count = 0;
  if ((i - 1) >= 0)
    if (tetro[i - 1][j] == '#')
      count++;
  if ((i + 1) <= 3)
    if (tetro[i + 1][j] == '#')
      count++;
 if ((j - 1) >= 0)
    if (tetro[i][j - 1] == '#')
      count++;
 if ((j + 1) <= 3)
   if (tetro[i][j + 1] == '#')
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
  if (*first)
      while (tmp->next)
	{
	  tmp = tmp->next;
	  c++;
	}
  new = (t_block*)malloc(sizeof(t_block));
  new->tetro = block;
  new->chr = c;
  new->next = NULL;
  if (!*first)
    *first = new;
  else
    tmp->next = new;
}

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

/*
  amount_x finds how much a tetromino has to be shifted to the left
*/

int amount_x(char **tetro)
{
  int row;
  int col;

  col = 0;
  while (col < 4)
    {
      row = 0;
      while(row < 4)
	  if (tetro[row++][col] == '#')
	    return (col);
      col++;
    }
  return (0);
}

/*
  amount_x finds how much a tetromino has to be shifted up
*/

int amount_y(char **tetro)
{
  int row;
  int col;

  row = 0;
  while (row < 4)
    {
      col = 0;
      while(col < 4)
	  if (tetro[row][col++] == '#')
	    return (row);
      row++;
    }
  return (0);
}

/*
  shift_tetro shifts the tetromino on the x and y axis to the upper left corner
*/
void	shift_tetro(char **tetro)
{
  int row;
  int col;
  int xy[2];

  xy[0] = amount_x(tetro);
  xy[1] = amount_y(tetro);
  row = 0;
  while (row < 4)
    {
      col = 0;
      while (col < 4)
	{
	  if ((tetro)[row][col] == '#')
	    {
	      (tetro)[row][col] = '.';
	      (tetro)[row - xy[1]][col - xy[0]] = '#';
	    }
	  col++;
	}
      row++;
    }
}

int		main(int argc, char **argv)
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
	print_blocks(blocks);
    }
  return (0);
}
