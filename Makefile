# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 18:28:14 by kurosawaits       #+#    #+#              #
#    Updated: 2023/04/14 23:25:23 by kurosawaits      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	minitalk
SERVER_NAME	=	server
CLIENT_NAME	=	client

SERVER_SRC	=	server.c
CLIENT_SRC	=	client.c

SERVER_OBJ	=	$(SERVER_SRC:.c=.o)
CLIENT_OBJ	=	$(CLIENT_SRC:.c=.o)

CC	=	gcc

CFLAGS = -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(SERVER_NAME) $(CLIENT_NAME)

$(SERVER_NAME):	$(SERVER_OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(SERVER_OBJ) -L ./libft -lft -o $@

$(CLIENT_NAME):	$(CLIENT_OBJ)
	make -C ./libft
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -L ./libft -lft -o $@

clean:
			rm -f $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: 	clean
			rm -f $(SERVER_NAME) $(CLIENT_NAME) ./libft/*.o ./libft/libft.a

re:			fclean	all

.PHONY:		all clean fclean re
