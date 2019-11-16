//ADD HEADER

#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "../libft/get_next_line.h"

int	store_blocks(t_block **first, char *file)
{
  int fd;
  char **buf;
  char *tmp;
  int i;
  
  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  if (!(buf = (char**)malloc(sizeof(*buf) * 4)))
    return (0);
  i = 0;
  while (i < 4)
    {
      if (get_next_line(fd, &buf[i]) > 1 || ft_strlen(buf[i++]) != 4)
	return (0);
      ft_putendl(buf[i - 1]); //temporary output for debugging
    }
  return (check_block(buf)); //function to check if tetromino is valid
}

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
  return ((adj >= 6));
}

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
  new->tetro = block;
  new->chr = c;
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
	ft_putstr("tetromino is valid");
    }
  return (0);
}

