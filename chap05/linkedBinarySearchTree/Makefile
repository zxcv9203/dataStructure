# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sujilee <sujilee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/14 22:30:00 by mki               #+#    #+#              #
#    Updated: 2021/12/16 17:06:12 by sujilee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = binarySearchTree
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

FILE = createBinSearchTree\
				insertElementBST\
				deleteElementBST\
				searchBST\
				searchRecursiveBST\
				searchInternalRecursiveBST\
				searchLeftMaxNode\
				deleteBinSearchTree\
				deleteBinSearchTreeInternal\
				displayBST\
				main

INCS = ./includes

SRCS_DIR = ./srcs/
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILE))) 
OBJS_DIR = ./srcs/
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILE))) 

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $< -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all bonus clean fclean re
