#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2019/10/16 14:45:39 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRCS = *.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) -Wall -Werror -Wextra

clean:
	/bin/rm -f $(OUTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
