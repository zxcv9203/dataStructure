SRCS =	linkeddeque.c

OBJS = $(SRCS:.c=.o)

NAME = libqueue.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean		:
				rm -f $(OBJS)

fclean		:	clean
				rm -f $(NAME)
			
re			:	fclean $(NAME)

.PHONY		:	all clean fclean re