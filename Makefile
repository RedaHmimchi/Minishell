# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 15:14:35 by rhmimchi          #+#    #+#              #
#    Updated: 2024/06/26 08:17:03 by rhmimchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
HEADER = minishell.h
SRC = main.c tools.c export.c echo.c cmds.c parser.c
OBJ = $(SRC:.c=.o)
CFLAGS = -g

READLINE_L = $(shell brew --prefix readline)/lib
READLINE_I = $(shell brew --prefix readline)/include

all: $(NAME)  

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L$(READLINE_L) $^ -lreadline -o $@


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -I$(READLINE_I) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all