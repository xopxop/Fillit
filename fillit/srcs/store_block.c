/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_block.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dthan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 00:24:23 by dthan             #+#    #+#             */
/*   Updated: 2019/11/19 01:02:37 by dthan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

void	add_block(t_block **first, char **block)
{
	t_block *tmp;
	t_block *new;
	char c;

	c = 'A';
	tmp = *first;
	if (*first)
	  {
	    c = 'B';
		while (tmp->next)
		{
			tmp = tmp->next;
			c++;
		}
	  }
	new = (t_block*)malloc(sizeof(t_block));
	new->tetro = block;
	new->chr = c;
	change_char(new);
	new->next = NULL;
	if (!*first)
		*first = new;
	else
		tmp->next = new;
}

void	change_char(t_block *block)
{
  int i;
  int j;

  i = 0;
  while (i < 4)
    {
      j = 0;
      while (j < 4)
	  if (block->tetro[i][j++] == '#')
	    block->tetro[i][j - 1] = block->chr;
      i++;
    }
}
