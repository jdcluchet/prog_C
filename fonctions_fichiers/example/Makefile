# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcluchet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 10:47:39 by pcluchet          #+#    #+#              #
#    Updated: 2018/09/12 17:49:13 by pcluchet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lire_delim

SRC_DIR = ./src/

CC = gcc

FILES = main.c\
	affichage.c\

O_FILES = $(C_WITH_PATH:.c=.o)

H_DIR = "./includes/"

CFLAGS = -I$(H_DIR)

C_WITH_PATH = $(addprefix $(SRC_DIR),$(FILES))

all : $(NAME)

$(NAME) : $(O_FILES)
	$(CC) -o $(NAME) $(O_FILES) $(CFLAGS)
clean :
	rm -f $(O_FILES)

fclean : clean
	rm -f $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all re clean fclean
