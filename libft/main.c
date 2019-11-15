#include <stdio.h>
#include <string.h>
#include "libft.h"

char *ft_strrep(char *, const char*, const char*);

int	size(t_list *elem)
{
  if (elem->content_size < 6)
    return (0);
  return (1);
}

int	main(void)
{
  t_list *lst;

  lst = ft_strsplitlst("Hello World testing test 123", ' ');
  ft_putlst(lst);
  return (0);
}
