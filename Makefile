# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouazi <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 20:08:27 by abouazi           #+#    #+#              #
#    Updated: 2022/03/16 20:08:31 by abouazi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CM = cc
FLAGS = -Wall -Wextra -Werror
INCLUDE = minitalk.h 

all: $(CLIENT) $(SERVER)

$(CLIENT) : 
    @$(CM) $(FLAGS) client.c  -o client

$(SERVER) :
    @$(CM) $(FLAGS) server.c  -o server

%.o:%.c $(INCLUDE)
    @$(CM) $(FLAGS)

clean:
    @rm -rf server client 

fclean: clean
    @rm -rf $(CLIENT) $(SERVER)

re: fclean all
