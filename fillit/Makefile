#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#*   Updated: 2019/11/19 00:48:16 by dthan            ###   ########.fr       *#
#                                                                              #
#******************************************************************************#

NAME=fillit
SRCS=./srcs/*.c
OBJS=./*.o
INCL=-I includes/
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS) $(INCL)
	gcc $(FLAGS) -o $(NAME) $(OBJS) ./libft/libft.a


clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C ./libft/ fclean

re: fclean all
