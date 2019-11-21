//ADD HEADER

#include "../includes/fillit.h"
#include "../../libft/libft.h"
#include <stdio.h>

char	**duplicate_grid(char **grid)
{
  char **grid_copy;
  int i;

  i = 0;
  while (grid[i])
    i++;
  if (!(grid_copy = (char**)malloc(sizeof(char*) * i + 1)))
    return (NULL);
  grid_copy[i--] = NULL;
  while (i >= 0)
    {
      grid_copy[i] = ft_strdup(grid[i]);
      i--;
    }
  return (grid_copy);
}

int	grid_find_empty(char **grid, int *gdyx)
{
  int y;
  int x;

  y = gdyx[0];
  x = gdyx[1];
  while (grid[y])
    {
      while (grid[y][x])
	if (grid[y][x++] == '.')
	  {
	    gdyx[0] = y;
	    gdyx[1] = x - 1;
	    return (1);
	  }
      y++;
      x = 0;
    }
  return (0);
}

int	place_tetro(char **grid, int gridy, int gridx, char **tetro)
{
  int x;
  int y;

  if (!check_tetro_fit(grid, gridy, gridx, tetro))
    return (0);
  y = 0;
  while (grid[y + gridy] && y < 4)
    {
      x = 0;
      while (grid[y + gridy][x + gridx] && x < 4)
	{
	  if (grid[y + gridy][x + gridx] == '.')
	    if (tetro[y][x] != '.')
		grid[y + gridy][x + gridx] = tetro[y][x];
	  x++;
	}
      y++;
    }
  return (1);
}

int	check_tetro_fit(char **grid, int gridy, int gridx, char **tetro)
{
  int x;
  int y;
  int count;

  y = 0;
  count = 0;
  while (grid[y + gridy] && y < 4)
    {
      x = 0;
      while (grid[y + gridy][x + gridx] && x < 4)
	{
	  if (grid[y + gridy][x + gridx] == '.')
	    if (tetro[y][x] != '.')
	      {
		count++;
	      }
	  x++;
	}
      y++;
    }
  return ((count == 4));
}

char	**place_blocks(char **prev_grid, t_block *block)
{
  char **grid;
  char **result;
  int gdyx[2];

  gdyx[0] = 0;
  gdyx[1] = 0;
  grid = duplicate_grid(prev_grid);
  while (1)
    {
      if (!grid_find_empty(grid, gdyx))
	return (NULL);
      if (place_tetro(grid, gdyx[0], gdyx[1], block->tetro))
	{
	  if (block->next == NULL)
	    return (grid);
	  result = place_blocks(grid, block->next);
	  if (result)
	    return (result);
	  grid = duplicate_grid(prev_grid);
	}
      gdyx[1]++;
    } 
}

char	**board_bigger(char **grid)
{
  int i;

  i = 0;
  while (grid[i])
    i++;
  return (gen_board(i + 1));
}

char	**fill_board(t_block *blocks)
{
  char **grid;
  char **result;

  grid = gen_board(board_starting_size(count_tetromines(blocks)));
  while (1)
    {
      result = place_blocks(grid, blocks);
      if (result)
	return (result);
      grid = board_bigger(grid);
    }
}
