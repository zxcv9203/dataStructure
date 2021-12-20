SRCS =	linkedgraph.c \
		main.c \
		linkedlist.c

OBJS = $(SRCS:.c=.o)

NAME = graph

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

STACK_DIR = linkedstack

STACK = libstack.a

QUEUE_DIR = linkeddeque

QUEUE = libqueue.a

LIBCOM = -L. -lstack -lqueue

all			:	$(NAME)

$(NAME)		:	$(STACK) $(QUEUE) $(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBCOM)

$(STACK) 	:
				make -C $(STACK_DIR)
				mv $(STACK_DIR)/$(STACK) .

$(QUEUE)	:
				make -C $(QUEUE_DIR)
				mv $(QUEUE_DIR)/$(QUEUE) .

clean		:
				rm -f $(OBJS)
				make -C $(STACK_DIR) clean

fclean		:	clean
				rm -f $(NAME)
				rm -f $(STACK)
			
re			:	fclean $(NAME)

.PHONY		:	all clean fclean re