# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idelemen <idelemen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/26 15:21:18 by idelemen          #+#    #+#              #
#    Updated: 2024/02/28 11:35:57 by idelemen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_C = client
NAME_S = server
FLAGS = -Wall -Wextra -Werror
FILE1 = client.c 
FILE2 = server.c
CC = cc

all: $(NAME_C) $(NAME_S)

$(NAME_C):
	$(CC) $(FLAGS) $(FILE1) -o $(NAME_C) 

$(NAME_S):
	$(CC) $(FLAGS) $(FILE2) -o $(NAME_S)
 
clean:
	rm -f server
	rm -f client

fclean: 
	rm -f $(NAME_C)
	rm -f $(NAME_S)

re: fclean all

.PHONY: all clean fclean re