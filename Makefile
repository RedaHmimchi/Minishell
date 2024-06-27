# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 15:14:35 by rhmimchi          #+#    #+#              #
#    Updated: 2024/06/26 23:55:19 by rhmimchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
HEADER = minishell.h
SRC = main.c ./libft/tools.c export.c echo.c cmds.c parser.c signals.c ./libft/ft_split.c ./libft/ft_substr.c ./libft/ft_strjoin.c ./libft/ft_strndup.c
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