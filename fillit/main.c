//ADD HEADER

#include "../libft/libft.h"
#include "fillit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	store_blocks(t_block **first, char *file)
{
  int fd;
  char **buf;
  int i;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (0);
  if (!(buf = (char**)malloc(sizeof(*buf) * 4)))
    return (0);
  i = 0;
  while (i < 4)
    if ((read(fd, buf[i++], 4)) != 4)
      return (0);
  if (!check_block(buf)) //function to check if tetromino is valid
    return (0);
}

static void	add_block(t_block **first, char **block)
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
    }
  return (0);
}

