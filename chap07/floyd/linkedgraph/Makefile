SRCS =	linkedgraph.c \
		linkedlist.c

OBJS = $(SRCS:.c=.o)

NAME = libgraph.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I.

LIBCOM = -L. -lstack -lqueue

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)
				rm -f $(STACK)
			
re			:	fclean $(NAME)

.PHONY		:	all clean fclean re