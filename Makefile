#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sadawi <sadawi@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/16 12:10:11 by sadawi            #+#    #+#              #
#    Updated: 2019/11/27 17:20:43 by sadawi           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=fillit
SRCS=srcs/main.c srcs/board_ft.c srcs/check_ft.c srcs/collision_ft.c \
srcs/display_ft.c srcs/get_info_ft.c srcs/shifting_ft.c srcs/solve_ft.c \
srcs/store_block_ft.c srcs/ordination_ft.c srcs/free_ft.c
OBJS=*.o
FLAGS=-Wall -Wextra -Werror
RUN_LIB=make -C libft/ fclean && make -C libft/

all: $(NAME)

$(NAME):
	@$(RUN_LIB)
	gcc $(FLAGS) -c $(SRCS)
	gcc $(FLAGS) -o $(NAME) $(OBJS) libft/libft.a

clean:
	/bin/rm -f $(OBJS)
	make -C libft/ clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
