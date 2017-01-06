# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjia <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 15:32:21 by jjia              #+#    #+#              #
#    Updated: 2016/12/06 15:32:22 by jjia             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	get_next_line
CC			=	gcc
CFLAGS		+=	-Wall -Wextra -Werror -I headers/
OFLAGS		=	-c $(CFLAGS)


		#  libs & link cmd	#
LIB_DIR		=	./lib/
LIB_LINKS	=	-lft
LINK_LIBS	=	-L $(LIB_DIR) $(LIB_LINKS)


		#	  files/folders		#
MAIN		=	main.c
CFILES		=	get_next_line.c

OFILES		= $(CFILES:.c=.o)


all: $(NAME)


$(NAME): $(OFILES)
	$(MAKE) -C ./libft
	mkdir lib
	mv ./libft/libft.a ./lib/
	$(CC) $(CFLAGS) -o $(NAME) $(MAIN) $(OFILES) $(LINK_LIBS)

clean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean

fclean:
	/bin/rm -rf $(OFILES)
	$(MAKE) -C ./libft clean
	/bin/rm -rf ./lib/libft.a
	/bin/rm -rf ./lib
	/bin/rm -rf $(NAME)

re: fclean all
